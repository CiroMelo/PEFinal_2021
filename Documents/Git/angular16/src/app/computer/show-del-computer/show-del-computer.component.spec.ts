import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ShowDelComputerComponent } from './show-del-computer.component';

describe('ShowDelComputerComponent', () => {
  let component: ShowDelComputerComponent;
  let fixture: ComponentFixture<ShowDelComputerComponent>;

  beforeEach(() => {
    TestBed.configureTestingModule({
      declarations: [ShowDelComputerComponent]
    });
    fixture = TestBed.createComponent(ShowDelComputerComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
