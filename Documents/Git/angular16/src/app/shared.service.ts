import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http'
import { Observable } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class SharedService {
  readonly APIUrl = 'UrlDaApiAqui'
  readonly PhotoUrl = 'UrlDaApiAqui'


  constructor(private http:HttpClient) { }

  getComputerList(): Observable<any[]>{
    return this.http.get<any>(this.APIUrl+'/Computer');
  }

  addComputer(val:any){
    return this.http.post(this.APIUrl+'/Computer', val)
  }

  updateComputer(val:any){
    return this.http.put(this.APIUrl+'/Computer', val)
  }

  deleteComputer(val:any){
    return this.http.delete(this.APIUrl+'/Computer', val)
  }
}
