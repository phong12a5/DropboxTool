#include <QCoreApplication>
#include <iostream>
#include <QDebug>
#include <CkJsonArray.h>
#include <CkJsonObject.h>
#include <CkStringBuilder.h>
#include <CkRest.h>
#include <CkGlobal.h>
#include <QFile>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <CkStream.h>

using namespace std;
CkGlobal glob;

bool unlockChilkat() {
    bool success_global = glob.UnlockBundle("VONGTH.CB4082020_9kru5rnD5R2h");
    if (success_global != true) {
        return false;
    }

    int status = glob.get_UnlockStatus();
    if (status == 2) {
        return true;
    } else {
        return false;
    }
}

bool deleteFile(const char * path) {
    CkRest rest;
    bool success;

    bool bTls = true;
    int port = 443;
    bool bAutoReconnect = true;
    success = rest.Connect("api.dropboxapi.com",port,bTls,bAutoReconnect);
    if (success != true) {
        std::cout << "ConnectFailReason: " << rest.get_ConnectFailReason() << "\r\n";
        std::cout << rest.lastErrorText() << "\r\n";
    } else {

        //  See the Online Tool for Generating JSON Creation Code
        CkJsonObject json;
        json.UpdateString("path",path);

        rest.AddHeader("Authorization","Bearer lr7usq7SigAAAAAAAAAAZ74c-zhZd2jOrNZLkp15x1JMx4uSgvLRlMIrXlNoYVQN");
        rest.AddHeader("Content-Type","application/json");

        CkStringBuilder sbRequestBody;
        json.EmitSb(sbRequestBody);
        CkStringBuilder sbResponseBody;
        success = rest.FullRequestSb("POST","/2/files/delete_v2",sbRequestBody,sbResponseBody);
        if (success != true) {
            std::cout << rest.lastErrorText() << "\r\n";
        } else {
            int respStatusCode = rest.get_ResponseStatusCode();
            if (respStatusCode >= 400) {
                success = false;
                std::cout << "Response Status Code = " << respStatusCode << "\r\n";
                std::cout << "Response Header:" << "\r\n";
                std::cout << rest.responseHeader() << "\r\n";
                std::cout << "Response Body:" << "\r\n";
                std::cout << sbResponseBody.getAsString() << "\r\n";
            } else {
                success = true;
            }
        }
    }
    qDebug() << "delete " << path << ": " << (success? "succecced" : "failed");
    return success;
}

CkJsonArray* getContentListFolder(QString cloudPath) {
    CkRest rest;
    bool success;

    CkJsonArray* result = new CkJsonArray();

    //  URL: https://api.dropboxapi.com/2/files/list_folder
    bool bTls = true;
    int port = 443;
    bool bAutoReconnect = true;
    success = rest.Connect("api.dropboxapi.com",port,bTls,bAutoReconnect);
    if (success != true) {
        std::cout << "ConnectFailReason: " << rest.get_ConnectFailReason() << "\r\n";
        std::cout << rest.lastErrorText() << "\r\n";
    } else {
        //  See the Online Tool for Generating JSON Creation Code
        QString cursor;
        bool has_more = false;
        do {
            CkJsonObject json;
            if(!has_more) {
                json.UpdateString("path",cloudPath.toUtf8().data());
                json.UpdateBool("recursive",false);
                json.UpdateBool("include_media_info",false);
                json.UpdateBool("include_deleted",false);
                json.UpdateBool("include_has_explicit_shared_members",false);
                json.UpdateBool("include_mounted_folders",true);
            } else {
                json.UpdateString("cursor",cursor.toUtf8().data());
            }

            rest.AddHeader("Authorization","Bearer lr7usq7SigAAAAAAAAAAZ74c-zhZd2jOrNZLkp15x1JMx4uSgvLRlMIrXlNoYVQN");
            rest.AddHeader("Content-Type","application/json");

            CkStringBuilder sbRequestBody;
            json.EmitSb(sbRequestBody);
            CkStringBuilder sbResponseBody;

            success = rest.FullRequestSb("POST", has_more? "/2/files/list_folder/continue" : "/2/files/list_folder", sbRequestBody, sbResponseBody);

            if (success != true) {
                std::cout << rest.lastErrorText() << "\r\n";
            } else {
                int respStatusCode = rest.get_ResponseStatusCode();
                if (respStatusCode >= 400) {
                    std::cout << "Response Status Code = " << respStatusCode << "\r\n";
                    std::cout << "Response Header:" << "\r\n";
                    std::cout << rest.responseHeader() << "\r\n";
                    std::cout << "Response Body:" << "\r\n";
                    std::cout << sbResponseBody.getAsString() << "\r\n";
                } else {

                    CkJsonObject jsonResponse;
                    jsonResponse.LoadSb(sbResponseBody);

                    //  See the Online Tool for Generating JSON Parse Code
                    int i;
                    int count_i;

                    cursor = jsonResponse.stringOf("cursor");
                    has_more = jsonResponse.BoolOf("has_more");
                    i = 0;
                    count_i = jsonResponse.SizeOfArray("entries");
                    while (i < count_i) {
                        jsonResponse.put_I(i);
                        const char *Tag = jsonResponse.stringOf("entries[i].\".tag\"");
                        const char *name = jsonResponse.stringOf("entries[i].name");
                        const char *path_lower = jsonResponse.stringOf("entries[i].path_lower");
                        const char *path_display = jsonResponse.stringOf("entries[i].path_display");
                        const char *id = jsonResponse.stringOf("entries[i].id");
                        const char *client_modified = jsonResponse.stringOf("entries[i].client_modified");
                        const char *server_modified = jsonResponse.stringOf("entries[i].server_modified");
                        const char *rev = jsonResponse.stringOf("entries[i].rev");
                        int size = jsonResponse.IntOf("entries[i].size");
                        const char *content_hash = jsonResponse.stringOf("entries[i].content_hash");

                        CkJsonObject object;
                        object.AddStringAt(-1,"type",Tag);
                        object.AddStringAt(-1,"name",name);
                        object.AddStringAt(-1,"path",path_display);
                        object.AddStringAt(-1,"client_modified",client_modified);
                        object.AddIntAt(-1,"size",size);
                        result->AddObjectCopyAt(-1,object);
                        i = i + 1;
                    }
                }
            }
        } while(has_more);
    }
    return result;
}

void printCloudFolder(const char * path) {
    CkJsonArray* folderArr = getContentListFolder(path);
    for(int i = 0; i < folderArr->get_Size(); i++) {
        CkJsonObject* object = folderArr->ObjectAt(i);
        qDebug() << object->stringOf("path");
    }
}

bool uploadFile(const char * source, const char * dest) {
    qDebug() << "uploadFile: " << source << " -- to: " << dest;
    CkRest rest;

   //  Connect to Dropbox
   bool success = rest.Connect("content.dropboxapi.com",443,true,true);
   if (success != true) {
       qDebug() << rest.lastErrorText();
       return false;
   }

   //  Add request headers.
   rest.AddHeader("Content-Type","application/octet-stream");
   rest.AddHeader("Authorization","Bearer lr7usq7SigAAAAAAAAAAZ74c-zhZd2jOrNZLkp15x1JMx4uSgvLRlMIrXlNoYVQN");


   QJsonObject json;
   json["path"] = dest;
   json["mode"] = "add";
   json["autorename"] = true;
   json["mute"] = false;
   rest.AddHeader("Dropbox-API-Arg",QJsonDocument(json).toJson(QJsonDocument::Compact));

   //  Almost ready to go...
   //  Let's setup a file stream to point to a file.
   CkStream fileStream;
   fileStream.put_SourceFile(source);

   //  Do the upload.  The URL is https://content.dropboxapi.com/2/files/upload.
   //  We already connected to content.dropboxapi.com using TLS (i.e. HTTPS),
   //  so now we only need to specify the path "/2/files/upload".

   //  Note: The file is streamed directly from disk.  (The entire
   //  file will not be loaded into memory.)
   const char * responseStr = rest.fullRequestStream("POST","/2/files/upload",fileStream);
   if (rest.get_LastMethodSuccess() != true) {
       qDebug() << rest.lastErrorText();
       return false;
   }

   //  When successful, Dropbox responds with a 200 response code.
   if (rest.get_ResponseStatusCode() != 200) {
       //  Examine the request/response to see what happened.
       qDebug() << "response status code = " << rest.get_ResponseStatusCode();
       qDebug() << "response status text = " << rest.responseStatusText();
       qDebug() << "response header: " << rest.responseHeader();
       qDebug() << "response body (if any): " << responseStr;
       qDebug() << "LastRequestStartLine: " << rest.lastRequestStartLine();
       qDebug() << "LastRequestHeader: " << rest.lastRequestHeader();
       return false;
   }

    return true;
}

void uploadFolder(const char * source, const char * dest) {
    qDebug() << "uploadFolder: " << source  << " -- to: " <<  dest;
    QDir directory(source);
    QStringList images = directory.entryList(QStringList(),QDir::Files);
    foreach(QString filename, images) {
    //do whatever you need to do
        QString path = directory.absoluteFilePath(filename);
        qDebug() << "path: " << path;
        uploadFile(path.toUtf8().data(),QString(QString(dest) + "/" + filename).toUtf8().data());
    }
}

int main(int argc, char *argv[])
{
    unlockChilkat();



    uploadFolder("/Users/phongdang/Temp/Test", "/zalo");
    printCloudFolder("/zalo");

    return 0;
}
