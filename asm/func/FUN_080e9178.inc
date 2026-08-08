	push {r4, r5, lr}
	adds r2, r0, #0
	ldr r1, _080E9198 @ =0x000001DF
	adds r0, r2, r1
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #0x1a
	bls _080E918C
	bl _080EAFD2
_080E918C:
	lsls r0, r0, #2
	ldr r1, _080E919C @ =_080E91A0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080E9198: .4byte 0x000001DF
_080E919C: .4byte _080E91A0
_080E91A0: @ jump table
	.4byte _080E9384 @ case 0
	.4byte _080E94C8 @ case 1
	.4byte _080E960C @ case 2
	.4byte _080E920C @ case 3
	.4byte _080E9DB4 @ case 4
	.4byte _080E9DB4 @ case 5
	.4byte _080E9DB4 @ case 6
	.4byte _080EA048 @ case 7
	.4byte _080EA804 @ case 8
	.4byte _080E9B24 @ case 9
	.4byte _080E9C6C @ case 10
	.4byte _080EAFD2 @ case 11
	.4byte _080EAD14 @ case 12
	.4byte _080E9750 @ case 13
	.4byte _080E9894 @ case 14
	.4byte _080EAFD2 @ case 15
	.4byte _080EA424 @ case 16
	.4byte _080EA190 @ case 17
	.4byte _080EA2D8 @ case 18
	.4byte _080EA6B8 @ case 19
	.4byte _080E9EFC @ case 20
	.4byte _080EA56C @ case 21
	.4byte _080EABD0 @ case 22
	.4byte _080E99D8 @ case 23
	.4byte _080EA948 @ case 24
	.4byte _080EAA8C @ case 25
	.4byte _080EAE54 @ case 26
_080E920C:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080E922C @ =0x030046A0
	ldr r0, [r2]
	adds r1, #0xe2
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080E9230 @ =0x0000270E
	cmp r1, r0
	bgt _080E9234
	adds r0, r5, #1
	b _080E9238
	.align 2, 0
_080E922C: .4byte 0x030046A0
_080E9230: .4byte 0x0000270E
_080E9234:
	ldr r1, _080E925C @ =0x0000270F
	adds r0, r1, #0
_080E9238:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080E927C
	ldr r2, _080E9260 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080E925C @ =0x0000270F
	cmp r1, r0
	ble _080E9264
	adds r1, r0, #0
	b _080E926A
	.align 2, 0
_080E925C: .4byte 0x0000270F
_080E9260: .4byte 0x030046A0
_080E9264:
	cmp r1, #0
	bge _080E926A
	movs r1, #0
_080E926A:
	ldr r2, _080E9278 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E9278: .4byte 0x030046A0
_080E927C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080E92C4
	ldr r1, _080E92A0 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E92A4 @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E92A8 @ =0x0000270F
	cmp r1, r0
	ble _080E92AC
	adds r1, r0, #0
	b _080E92B2
	.align 2, 0
_080E92A0: .4byte 0x030046A0
_080E92A4: .4byte 0x0000022A
_080E92A8: .4byte 0x0000270F
_080E92AC:
	cmp r1, #0
	bge _080E92B2
	movs r1, #0
_080E92B2:
	ldr r2, _080E92BC @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E92C0 @ =0x0000022A
	bl _080EAFCE
	.align 2, 0
_080E92BC: .4byte 0x030046A0
_080E92C0: .4byte 0x0000022A
_080E92C4:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080E9308
	ldr r1, _080E92E8 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E92EC @ =0x0000270F
	cmp r1, r0
	ble _080E92F0
	adds r1, r0, #0
	b _080E92F6
	.align 2, 0
_080E92E8: .4byte 0x030046A0
_080E92EC: .4byte 0x0000270F
_080E92F0:
	cmp r1, #0
	bge _080E92F6
	movs r1, #0
_080E92F6:
	ldr r2, _080E9304 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E9304: .4byte 0x030046A0
_080E9308:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	beq _080E9350
	ldr r1, _080E932C @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E9330 @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9334 @ =0x0000270F
	cmp r1, r0
	ble _080E9338
	adds r1, r0, #0
	b _080E933E
	.align 2, 0
_080E932C: .4byte 0x030046A0
_080E9330: .4byte 0x0000022E
_080E9334: .4byte 0x0000270F
_080E9338:
	cmp r1, #0
	bge _080E933E
	movs r1, #0
_080E933E:
	ldr r2, _080E9348 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E934C @ =0x0000022E
	bl _080EAFCE
	.align 2, 0
_080E9348: .4byte 0x030046A0
_080E934C: .4byte 0x0000022E
_080E9350:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r4, r0
	cmp r4, #0
	bne _080E935E
	bl _080EAFD2
_080E935E:
	ldr r1, _080E937C @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9380 @ =0x0000270F
	cmp r1, r0
	ble _080E9378
	bl FUN_080eafb4
_080E9378:
	bl _080EAFC0
	.align 2, 0
_080E937C: .4byte 0x030046A0
_080E9380: .4byte 0x0000270F
_080E9384:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080E93A4 @ =0x030046A0
	ldr r0, [r2]
	adds r1, #0xe4
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080E93A8 @ =0x0000270E
	cmp r1, r0
	bgt _080E93AC
	adds r0, r5, #1
	b _080E93B0
	.align 2, 0
_080E93A4: .4byte 0x030046A0
_080E93A8: .4byte 0x0000270E
_080E93AC:
	ldr r1, _080E93D4 @ =0x0000270F
	adds r0, r1, #0
_080E93B0:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080E93F4
	ldr r2, _080E93D8 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080E93D4 @ =0x0000270F
	cmp r1, r0
	ble _080E93DC
	adds r1, r0, #0
	b _080E93E2
	.align 2, 0
_080E93D4: .4byte 0x0000270F
_080E93D8: .4byte 0x030046A0
_080E93DC:
	cmp r1, #0
	bge _080E93E2
	movs r1, #0
_080E93E2:
	ldr r2, _080E93F0 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E93F0: .4byte 0x030046A0
_080E93F4:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080E943C
	ldr r1, _080E9418 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E941C @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9420 @ =0x0000270F
	cmp r1, r0
	ble _080E9424
	adds r1, r0, #0
	b _080E942A
	.align 2, 0
_080E9418: .4byte 0x030046A0
_080E941C: .4byte 0x0000022A
_080E9420: .4byte 0x0000270F
_080E9424:
	cmp r1, #0
	bge _080E942A
	movs r1, #0
_080E942A:
	ldr r2, _080E9434 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E9438 @ =0x0000022A
	bl _080EAFCE
	.align 2, 0
_080E9434: .4byte 0x030046A0
_080E9438: .4byte 0x0000022A
_080E943C:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080E9480
	ldr r1, _080E9460 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9464 @ =0x0000270F
	cmp r1, r0
	ble _080E9468
	adds r1, r0, #0
	b _080E946E
	.align 2, 0
_080E9460: .4byte 0x030046A0
_080E9464: .4byte 0x0000270F
_080E9468:
	cmp r1, #0
	bge _080E946E
	movs r1, #0
_080E946E:
	ldr r2, _080E947C @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E947C: .4byte 0x030046A0
_080E9480:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080E948C
	b _080E9350
_080E948C:
	ldr r1, _080E94A4 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E94A8 @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E94AC @ =0x0000270F
	cmp r1, r0
	ble _080E94B0
	adds r1, r0, #0
	b _080E94B6
	.align 2, 0
_080E94A4: .4byte 0x030046A0
_080E94A8: .4byte 0x0000022E
_080E94AC: .4byte 0x0000270F
_080E94B0:
	cmp r1, #0
	bge _080E94B6
	movs r1, #0
_080E94B6:
	ldr r2, _080E94C0 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E94C4 @ =0x0000022E
	bl _080EAFCE
	.align 2, 0
_080E94C0: .4byte 0x030046A0
_080E94C4: .4byte 0x0000022E
_080E94C8:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080E94E8 @ =0x030046A0
	ldr r0, [r2]
	adds r1, #0xe6
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080E94EC @ =0x0000270E
	cmp r1, r0
	bgt _080E94F0
	adds r0, r5, #1
	b _080E94F4
	.align 2, 0
_080E94E8: .4byte 0x030046A0
_080E94EC: .4byte 0x0000270E
_080E94F0:
	ldr r1, _080E9518 @ =0x0000270F
	adds r0, r1, #0
_080E94F4:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080E9538
	ldr r2, _080E951C @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080E9518 @ =0x0000270F
	cmp r1, r0
	ble _080E9520
	adds r1, r0, #0
	b _080E9526
	.align 2, 0
_080E9518: .4byte 0x0000270F
_080E951C: .4byte 0x030046A0
_080E9520:
	cmp r1, #0
	bge _080E9526
	movs r1, #0
_080E9526:
	ldr r2, _080E9534 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E9534: .4byte 0x030046A0
_080E9538:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080E9580
	ldr r1, _080E955C @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E9560 @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9564 @ =0x0000270F
	cmp r1, r0
	ble _080E9568
	adds r1, r0, #0
	b _080E956E
	.align 2, 0
_080E955C: .4byte 0x030046A0
_080E9560: .4byte 0x0000022A
_080E9564: .4byte 0x0000270F
_080E9568:
	cmp r1, #0
	bge _080E956E
	movs r1, #0
_080E956E:
	ldr r2, _080E9578 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E957C @ =0x0000022A
	bl _080EAFCE
	.align 2, 0
_080E9578: .4byte 0x030046A0
_080E957C: .4byte 0x0000022A
_080E9580:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080E95C4
	ldr r1, _080E95A4 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E95A8 @ =0x0000270F
	cmp r1, r0
	ble _080E95AC
	adds r1, r0, #0
	b _080E95B2
	.align 2, 0
_080E95A4: .4byte 0x030046A0
_080E95A8: .4byte 0x0000270F
_080E95AC:
	cmp r1, #0
	bge _080E95B2
	movs r1, #0
_080E95B2:
	ldr r2, _080E95C0 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E95C0: .4byte 0x030046A0
_080E95C4:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080E95D0
	b _080E9350
_080E95D0:
	ldr r1, _080E95E8 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E95EC @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E95F0 @ =0x0000270F
	cmp r1, r0
	ble _080E95F4
	adds r1, r0, #0
	b _080E95FA
	.align 2, 0
_080E95E8: .4byte 0x030046A0
_080E95EC: .4byte 0x0000022E
_080E95F0: .4byte 0x0000270F
_080E95F4:
	cmp r1, #0
	bge _080E95FA
	movs r1, #0
_080E95FA:
	ldr r2, _080E9604 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E9608 @ =0x0000022E
	bl _080EAFCE
	.align 2, 0
_080E9604: .4byte 0x030046A0
_080E9608: .4byte 0x0000022E
_080E960C:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080E962C @ =0x030046A0
	ldr r0, [r2]
	adds r1, #0xe8
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080E9630 @ =0x0000270E
	cmp r1, r0
	bgt _080E9634
	adds r0, r5, #1
	b _080E9638
	.align 2, 0
_080E962C: .4byte 0x030046A0
_080E9630: .4byte 0x0000270E
_080E9634:
	ldr r1, _080E965C @ =0x0000270F
	adds r0, r1, #0
_080E9638:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080E967C
	ldr r2, _080E9660 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080E965C @ =0x0000270F
	cmp r1, r0
	ble _080E9664
	adds r1, r0, #0
	b _080E966A
	.align 2, 0
_080E965C: .4byte 0x0000270F
_080E9660: .4byte 0x030046A0
_080E9664:
	cmp r1, #0
	bge _080E966A
	movs r1, #0
_080E966A:
	ldr r2, _080E9678 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E9678: .4byte 0x030046A0
_080E967C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080E96C4
	ldr r1, _080E96A0 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E96A4 @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E96A8 @ =0x0000270F
	cmp r1, r0
	ble _080E96AC
	adds r1, r0, #0
	b _080E96B2
	.align 2, 0
_080E96A0: .4byte 0x030046A0
_080E96A4: .4byte 0x0000022A
_080E96A8: .4byte 0x0000270F
_080E96AC:
	cmp r1, #0
	bge _080E96B2
	movs r1, #0
_080E96B2:
	ldr r2, _080E96BC @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E96C0 @ =0x0000022A
	bl _080EAFCE
	.align 2, 0
_080E96BC: .4byte 0x030046A0
_080E96C0: .4byte 0x0000022A
_080E96C4:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080E9708
	ldr r1, _080E96E8 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E96EC @ =0x0000270F
	cmp r1, r0
	ble _080E96F0
	adds r1, r0, #0
	b _080E96F6
	.align 2, 0
_080E96E8: .4byte 0x030046A0
_080E96EC: .4byte 0x0000270F
_080E96F0:
	cmp r1, #0
	bge _080E96F6
	movs r1, #0
_080E96F6:
	ldr r2, _080E9704 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E9704: .4byte 0x030046A0
_080E9708:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080E9714
	b _080E9350
_080E9714:
	ldr r1, _080E972C @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E9730 @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9734 @ =0x0000270F
	cmp r1, r0
	ble _080E9738
	adds r1, r0, #0
	b _080E973E
	.align 2, 0
_080E972C: .4byte 0x030046A0
_080E9730: .4byte 0x0000022E
_080E9734: .4byte 0x0000270F
_080E9738:
	cmp r1, #0
	bge _080E973E
	movs r1, #0
_080E973E:
	ldr r2, _080E9748 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E974C @ =0x0000022E
	bl _080EAFCE
	.align 2, 0
_080E9748: .4byte 0x030046A0
_080E974C: .4byte 0x0000022E
_080E9750:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080E9770 @ =0x030046A0
	ldr r0, [r2]
	adds r1, #0xf8
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080E9774 @ =0x0000270E
	cmp r1, r0
	bgt _080E9778
	adds r0, r5, #1
	b _080E977C
	.align 2, 0
_080E9770: .4byte 0x030046A0
_080E9774: .4byte 0x0000270E
_080E9778:
	ldr r1, _080E97A0 @ =0x0000270F
	adds r0, r1, #0
_080E977C:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080E97C0
	ldr r2, _080E97A4 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080E97A0 @ =0x0000270F
	cmp r1, r0
	ble _080E97A8
	adds r1, r0, #0
	b _080E97AE
	.align 2, 0
_080E97A0: .4byte 0x0000270F
_080E97A4: .4byte 0x030046A0
_080E97A8:
	cmp r1, #0
	bge _080E97AE
	movs r1, #0
_080E97AE:
	ldr r2, _080E97BC @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E97BC: .4byte 0x030046A0
_080E97C0:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080E9808
	ldr r1, _080E97E4 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E97E8 @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E97EC @ =0x0000270F
	cmp r1, r0
	ble _080E97F0
	adds r1, r0, #0
	b _080E97F6
	.align 2, 0
_080E97E4: .4byte 0x030046A0
_080E97E8: .4byte 0x0000022A
_080E97EC: .4byte 0x0000270F
_080E97F0:
	cmp r1, #0
	bge _080E97F6
	movs r1, #0
_080E97F6:
	ldr r2, _080E9800 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E9804 @ =0x0000022A
	bl _080EAFCE
	.align 2, 0
_080E9800: .4byte 0x030046A0
_080E9804: .4byte 0x0000022A
_080E9808:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080E984C
	ldr r1, _080E982C @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9830 @ =0x0000270F
	cmp r1, r0
	ble _080E9834
	adds r1, r0, #0
	b _080E983A
	.align 2, 0
_080E982C: .4byte 0x030046A0
_080E9830: .4byte 0x0000270F
_080E9834:
	cmp r1, #0
	bge _080E983A
	movs r1, #0
_080E983A:
	ldr r2, _080E9848 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E9848: .4byte 0x030046A0
_080E984C:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080E9858
	b _080E9350
_080E9858:
	ldr r1, _080E9870 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E9874 @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9878 @ =0x0000270F
	cmp r1, r0
	ble _080E987C
	adds r1, r0, #0
	b _080E9882
	.align 2, 0
_080E9870: .4byte 0x030046A0
_080E9874: .4byte 0x0000022E
_080E9878: .4byte 0x0000270F
_080E987C:
	cmp r1, #0
	bge _080E9882
	movs r1, #0
_080E9882:
	ldr r2, _080E988C @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E9890 @ =0x0000022E
	bl _080EAFCE
	.align 2, 0
_080E988C: .4byte 0x030046A0
_080E9890: .4byte 0x0000022E
_080E9894:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080E98B4 @ =0x030046A0
	ldr r0, [r2]
	adds r1, #0xfa
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080E98B8 @ =0x0000270E
	cmp r1, r0
	bgt _080E98BC
	adds r0, r5, #1
	b _080E98C0
	.align 2, 0
_080E98B4: .4byte 0x030046A0
_080E98B8: .4byte 0x0000270E
_080E98BC:
	ldr r1, _080E98E4 @ =0x0000270F
	adds r0, r1, #0
_080E98C0:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080E9904
	ldr r2, _080E98E8 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080E98E4 @ =0x0000270F
	cmp r1, r0
	ble _080E98EC
	adds r1, r0, #0
	b _080E98F2
	.align 2, 0
_080E98E4: .4byte 0x0000270F
_080E98E8: .4byte 0x030046A0
_080E98EC:
	cmp r1, #0
	bge _080E98F2
	movs r1, #0
_080E98F2:
	ldr r2, _080E9900 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E9900: .4byte 0x030046A0
_080E9904:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080E994C
	ldr r1, _080E9928 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E992C @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9930 @ =0x0000270F
	cmp r1, r0
	ble _080E9934
	adds r1, r0, #0
	b _080E993A
	.align 2, 0
_080E9928: .4byte 0x030046A0
_080E992C: .4byte 0x0000022A
_080E9930: .4byte 0x0000270F
_080E9934:
	cmp r1, #0
	bge _080E993A
	movs r1, #0
_080E993A:
	ldr r2, _080E9944 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E9948 @ =0x0000022A
	bl _080EAFCE
	.align 2, 0
_080E9944: .4byte 0x030046A0
_080E9948: .4byte 0x0000022A
_080E994C:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080E9990
	ldr r1, _080E9970 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9974 @ =0x0000270F
	cmp r1, r0
	ble _080E9978
	adds r1, r0, #0
	b _080E997E
	.align 2, 0
_080E9970: .4byte 0x030046A0
_080E9974: .4byte 0x0000270F
_080E9978:
	cmp r1, #0
	bge _080E997E
	movs r1, #0
_080E997E:
	ldr r2, _080E998C @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E998C: .4byte 0x030046A0
_080E9990:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080E999C
	b _080E9350
_080E999C:
	ldr r1, _080E99B4 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E99B8 @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E99BC @ =0x0000270F
	cmp r1, r0
	ble _080E99C0
	adds r1, r0, #0
	b _080E99C6
	.align 2, 0
_080E99B4: .4byte 0x030046A0
_080E99B8: .4byte 0x0000022E
_080E99BC: .4byte 0x0000270F
_080E99C0:
	cmp r1, #0
	bge _080E99C6
	movs r1, #0
_080E99C6:
	ldr r2, _080E99D0 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E99D4 @ =0x0000022E
	bl _080EAFCE
	.align 2, 0
_080E99D0: .4byte 0x030046A0
_080E99D4: .4byte 0x0000022E
_080E99D8:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080E99FC @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x88
	lsls r1, r1, #2
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080E9A00 @ =0x0000270E
	cmp r1, r0
	bgt _080E9A04
	adds r0, r5, #1
	b _080E9A08
	.align 2, 0
_080E99FC: .4byte 0x030046A0
_080E9A00: .4byte 0x0000270E
_080E9A04:
	ldr r1, _080E9A2C @ =0x0000270F
	adds r0, r1, #0
_080E9A08:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080E9A4C
	ldr r2, _080E9A30 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080E9A2C @ =0x0000270F
	cmp r1, r0
	ble _080E9A34
	adds r1, r0, #0
	b _080E9A3A
	.align 2, 0
_080E9A2C: .4byte 0x0000270F
_080E9A30: .4byte 0x030046A0
_080E9A34:
	cmp r1, #0
	bge _080E9A3A
	movs r1, #0
_080E9A3A:
	ldr r2, _080E9A48 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E9A48: .4byte 0x030046A0
_080E9A4C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080E9A94
	ldr r1, _080E9A70 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E9A74 @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9A78 @ =0x0000270F
	cmp r1, r0
	ble _080E9A7C
	adds r1, r0, #0
	b _080E9A82
	.align 2, 0
_080E9A70: .4byte 0x030046A0
_080E9A74: .4byte 0x0000022A
_080E9A78: .4byte 0x0000270F
_080E9A7C:
	cmp r1, #0
	bge _080E9A82
	movs r1, #0
_080E9A82:
	ldr r2, _080E9A8C @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E9A90 @ =0x0000022A
	bl _080EAFCE
	.align 2, 0
_080E9A8C: .4byte 0x030046A0
_080E9A90: .4byte 0x0000022A
_080E9A94:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080E9AD8
	ldr r1, _080E9AB8 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9ABC @ =0x0000270F
	cmp r1, r0
	ble _080E9AC0
	adds r1, r0, #0
	b _080E9AC6
	.align 2, 0
_080E9AB8: .4byte 0x030046A0
_080E9ABC: .4byte 0x0000270F
_080E9AC0:
	cmp r1, #0
	bge _080E9AC6
	movs r1, #0
_080E9AC6:
	ldr r2, _080E9AD4 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E9AD4: .4byte 0x030046A0
_080E9AD8:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080E9AE6
	bl _080E9350
_080E9AE6:
	ldr r1, _080E9B00 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E9B04 @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9B08 @ =0x0000270F
	cmp r1, r0
	ble _080E9B0C
	adds r1, r0, #0
	b _080E9B12
	.align 2, 0
_080E9B00: .4byte 0x030046A0
_080E9B04: .4byte 0x0000022E
_080E9B08: .4byte 0x0000270F
_080E9B0C:
	cmp r1, #0
	bge _080E9B12
	movs r1, #0
_080E9B12:
	ldr r2, _080E9B1C @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E9B20 @ =0x0000022E
	bl _080EAFCE
	.align 2, 0
_080E9B1C: .4byte 0x030046A0
_080E9B20: .4byte 0x0000022E
_080E9B24:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080E9B44 @ =0x030046A0
	ldr r0, [r2]
	adds r1, #0xf0
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080E9B48 @ =0x0000270E
	cmp r1, r0
	bgt _080E9B4C
	adds r0, r5, #1
	b _080E9B50
	.align 2, 0
_080E9B44: .4byte 0x030046A0
_080E9B48: .4byte 0x0000270E
_080E9B4C:
	ldr r1, _080E9B74 @ =0x0000270F
	adds r0, r1, #0
_080E9B50:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080E9B94
	ldr r2, _080E9B78 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080E9B74 @ =0x0000270F
	cmp r1, r0
	ble _080E9B7C
	adds r1, r0, #0
	b _080E9B82
	.align 2, 0
_080E9B74: .4byte 0x0000270F
_080E9B78: .4byte 0x030046A0
_080E9B7C:
	cmp r1, #0
	bge _080E9B82
	movs r1, #0
_080E9B82:
	ldr r2, _080E9B90 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E9B90: .4byte 0x030046A0
_080E9B94:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080E9BDC
	ldr r1, _080E9BB8 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E9BBC @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9BC0 @ =0x0000270F
	cmp r1, r0
	ble _080E9BC4
	adds r1, r0, #0
	b _080E9BCA
	.align 2, 0
_080E9BB8: .4byte 0x030046A0
_080E9BBC: .4byte 0x0000022A
_080E9BC0: .4byte 0x0000270F
_080E9BC4:
	cmp r1, #0
	bge _080E9BCA
	movs r1, #0
_080E9BCA:
	ldr r2, _080E9BD4 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E9BD8 @ =0x0000022A
	bl _080EAFCE
	.align 2, 0
_080E9BD4: .4byte 0x030046A0
_080E9BD8: .4byte 0x0000022A
_080E9BDC:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080E9C20
	ldr r1, _080E9C00 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9C04 @ =0x0000270F
	cmp r1, r0
	ble _080E9C08
	adds r1, r0, #0
	b _080E9C0E
	.align 2, 0
_080E9C00: .4byte 0x030046A0
_080E9C04: .4byte 0x0000270F
_080E9C08:
	cmp r1, #0
	bge _080E9C0E
	movs r1, #0
_080E9C0E:
	ldr r2, _080E9C1C @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E9C1C: .4byte 0x030046A0
_080E9C20:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080E9C2E
	bl _080E9350
_080E9C2E:
	ldr r1, _080E9C48 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E9C4C @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9C50 @ =0x0000270F
	cmp r1, r0
	ble _080E9C54
	adds r1, r0, #0
	b _080E9C5A
	.align 2, 0
_080E9C48: .4byte 0x030046A0
_080E9C4C: .4byte 0x0000022E
_080E9C50: .4byte 0x0000270F
_080E9C54:
	cmp r1, #0
	bge _080E9C5A
	movs r1, #0
_080E9C5A:
	ldr r2, _080E9C64 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E9C68 @ =0x0000022E
	bl _080EAFCE
	.align 2, 0
_080E9C64: .4byte 0x030046A0
_080E9C68: .4byte 0x0000022E
_080E9C6C:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080E9C8C @ =0x030046A0
	ldr r0, [r2]
	adds r1, #0xf2
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080E9C90 @ =0x0000270E
	cmp r1, r0
	bgt _080E9C94
	adds r0, r5, #1
	b _080E9C98
	.align 2, 0
_080E9C8C: .4byte 0x030046A0
_080E9C90: .4byte 0x0000270E
_080E9C94:
	ldr r1, _080E9CBC @ =0x0000270F
	adds r0, r1, #0
_080E9C98:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080E9CDC
	ldr r2, _080E9CC0 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080E9CBC @ =0x0000270F
	cmp r1, r0
	ble _080E9CC4
	adds r1, r0, #0
	b _080E9CCA
	.align 2, 0
_080E9CBC: .4byte 0x0000270F
_080E9CC0: .4byte 0x030046A0
_080E9CC4:
	cmp r1, #0
	bge _080E9CCA
	movs r1, #0
_080E9CCA:
	ldr r2, _080E9CD8 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E9CD8: .4byte 0x030046A0
_080E9CDC:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080E9D24
	ldr r1, _080E9D00 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E9D04 @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9D08 @ =0x0000270F
	cmp r1, r0
	ble _080E9D0C
	adds r1, r0, #0
	b _080E9D12
	.align 2, 0
_080E9D00: .4byte 0x030046A0
_080E9D04: .4byte 0x0000022A
_080E9D08: .4byte 0x0000270F
_080E9D0C:
	cmp r1, #0
	bge _080E9D12
	movs r1, #0
_080E9D12:
	ldr r2, _080E9D1C @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E9D20 @ =0x0000022A
	bl _080EAFCE
	.align 2, 0
_080E9D1C: .4byte 0x030046A0
_080E9D20: .4byte 0x0000022A
_080E9D24:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080E9D68
	ldr r1, _080E9D48 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9D4C @ =0x0000270F
	cmp r1, r0
	ble _080E9D50
	adds r1, r0, #0
	b _080E9D56
	.align 2, 0
_080E9D48: .4byte 0x030046A0
_080E9D4C: .4byte 0x0000270F
_080E9D50:
	cmp r1, #0
	bge _080E9D56
	movs r1, #0
_080E9D56:
	ldr r2, _080E9D64 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E9D64: .4byte 0x030046A0
_080E9D68:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080E9D76
	bl _080E9350
_080E9D76:
	ldr r1, _080E9D90 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E9D94 @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9D98 @ =0x0000270F
	cmp r1, r0
	ble _080E9D9C
	adds r1, r0, #0
	b _080E9DA2
	.align 2, 0
_080E9D90: .4byte 0x030046A0
_080E9D94: .4byte 0x0000022E
_080E9D98: .4byte 0x0000270F
_080E9D9C:
	cmp r1, #0
	bge _080E9DA2
	movs r1, #0
_080E9DA2:
	ldr r2, _080E9DAC @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E9DB0 @ =0x0000022E
	bl _080EAFCE
	.align 2, 0
_080E9DAC: .4byte 0x030046A0
_080E9DB0: .4byte 0x0000022E
_080E9DB4:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080E9DD4 @ =0x030046A0
	ldr r0, [r2]
	adds r1, #0xea
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080E9DD8 @ =0x0000270E
	cmp r1, r0
	bgt _080E9DDC
	adds r0, r5, #1
	b _080E9DE0
	.align 2, 0
_080E9DD4: .4byte 0x030046A0
_080E9DD8: .4byte 0x0000270E
_080E9DDC:
	ldr r1, _080E9E04 @ =0x0000270F
	adds r0, r1, #0
_080E9DE0:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080E9E24
	ldr r2, _080E9E08 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080E9E04 @ =0x0000270F
	cmp r1, r0
	ble _080E9E0C
	adds r1, r0, #0
	b _080E9E12
	.align 2, 0
_080E9E04: .4byte 0x0000270F
_080E9E08: .4byte 0x030046A0
_080E9E0C:
	cmp r1, #0
	bge _080E9E12
	movs r1, #0
_080E9E12:
	ldr r2, _080E9E20 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E9E20: .4byte 0x030046A0
_080E9E24:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080E9E6C
	ldr r1, _080E9E48 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E9E4C @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9E50 @ =0x0000270F
	cmp r1, r0
	ble _080E9E54
	adds r1, r0, #0
	b _080E9E5A
	.align 2, 0
_080E9E48: .4byte 0x030046A0
_080E9E4C: .4byte 0x0000022A
_080E9E50: .4byte 0x0000270F
_080E9E54:
	cmp r1, #0
	bge _080E9E5A
	movs r1, #0
_080E9E5A:
	ldr r2, _080E9E64 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E9E68 @ =0x0000022A
	bl _080EAFCE
	.align 2, 0
_080E9E64: .4byte 0x030046A0
_080E9E68: .4byte 0x0000022A
_080E9E6C:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080E9EB0
	ldr r1, _080E9E90 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9E94 @ =0x0000270F
	cmp r1, r0
	ble _080E9E98
	adds r1, r0, #0
	b _080E9E9E
	.align 2, 0
_080E9E90: .4byte 0x030046A0
_080E9E94: .4byte 0x0000270F
_080E9E98:
	cmp r1, #0
	bge _080E9E9E
	movs r1, #0
_080E9E9E:
	ldr r2, _080E9EAC @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E9EAC: .4byte 0x030046A0
_080E9EB0:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080E9EBE
	bl _080E9350
_080E9EBE:
	ldr r1, _080E9ED8 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E9EDC @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9EE0 @ =0x0000270F
	cmp r1, r0
	ble _080E9EE4
	adds r1, r0, #0
	b _080E9EEA
	.align 2, 0
_080E9ED8: .4byte 0x030046A0
_080E9EDC: .4byte 0x0000022E
_080E9EE0: .4byte 0x0000270F
_080E9EE4:
	cmp r1, #0
	bge _080E9EEA
	movs r1, #0
_080E9EEA:
	ldr r2, _080E9EF4 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E9EF8 @ =0x0000022E
	bl _080EAFCE
	.align 2, 0
_080E9EF4: .4byte 0x030046A0
_080E9EF8: .4byte 0x0000022E
_080E9EFC:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080E9F1C @ =0x030046A0
	ldr r0, [r2]
	ldr r1, _080E9F20 @ =0x00000212
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080E9F24 @ =0x0000270E
	cmp r1, r0
	bgt _080E9F28
	adds r0, r5, #1
	b _080E9F2C
	.align 2, 0
_080E9F1C: .4byte 0x030046A0
_080E9F20: .4byte 0x00000212
_080E9F24: .4byte 0x0000270E
_080E9F28:
	ldr r1, _080E9F50 @ =0x0000270F
	adds r0, r1, #0
_080E9F2C:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080E9F70
	ldr r2, _080E9F54 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080E9F50 @ =0x0000270F
	cmp r1, r0
	ble _080E9F58
	adds r1, r0, #0
	b _080E9F5E
	.align 2, 0
_080E9F50: .4byte 0x0000270F
_080E9F54: .4byte 0x030046A0
_080E9F58:
	cmp r1, #0
	bge _080E9F5E
	movs r1, #0
_080E9F5E:
	ldr r2, _080E9F6C @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E9F6C: .4byte 0x030046A0
_080E9F70:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080E9FB8
	ldr r1, _080E9F94 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080E9F98 @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9F9C @ =0x0000270F
	cmp r1, r0
	ble _080E9FA0
	adds r1, r0, #0
	b _080E9FA6
	.align 2, 0
_080E9F94: .4byte 0x030046A0
_080E9F98: .4byte 0x0000022A
_080E9F9C: .4byte 0x0000270F
_080E9FA0:
	cmp r1, #0
	bge _080E9FA6
	movs r1, #0
_080E9FA6:
	ldr r2, _080E9FB0 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080E9FB4 @ =0x0000022A
	bl _080EAFCE
	.align 2, 0
_080E9FB0: .4byte 0x030046A0
_080E9FB4: .4byte 0x0000022A
_080E9FB8:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080E9FFC
	ldr r1, _080E9FDC @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080E9FE0 @ =0x0000270F
	cmp r1, r0
	ble _080E9FE4
	adds r1, r0, #0
	b _080E9FEA
	.align 2, 0
_080E9FDC: .4byte 0x030046A0
_080E9FE0: .4byte 0x0000270F
_080E9FE4:
	cmp r1, #0
	bge _080E9FEA
	movs r1, #0
_080E9FEA:
	ldr r2, _080E9FF8 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080E9FF8: .4byte 0x030046A0
_080E9FFC:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080EA00A
	bl _080E9350
_080EA00A:
	ldr r1, _080EA024 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EA028 @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA02C @ =0x0000270F
	cmp r1, r0
	ble _080EA030
	adds r1, r0, #0
	b _080EA036
	.align 2, 0
_080EA024: .4byte 0x030046A0
_080EA028: .4byte 0x0000022E
_080EA02C: .4byte 0x0000270F
_080EA030:
	cmp r1, #0
	bge _080EA036
	movs r1, #0
_080EA036:
	ldr r2, _080EA040 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EA044 @ =0x0000022E
	bl _080EAFCE
	.align 2, 0
_080EA040: .4byte 0x030046A0
_080EA044: .4byte 0x0000022E
_080EA048:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080EA068 @ =0x030046A0
	ldr r0, [r2]
	adds r1, #0xec
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080EA06C @ =0x0000270E
	cmp r1, r0
	bgt _080EA070
	adds r0, r5, #1
	b _080EA074
	.align 2, 0
_080EA068: .4byte 0x030046A0
_080EA06C: .4byte 0x0000270E
_080EA070:
	ldr r1, _080EA098 @ =0x0000270F
	adds r0, r1, #0
_080EA074:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080EA0B8
	ldr r2, _080EA09C @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080EA098 @ =0x0000270F
	cmp r1, r0
	ble _080EA0A0
	adds r1, r0, #0
	b _080EA0A6
	.align 2, 0
_080EA098: .4byte 0x0000270F
_080EA09C: .4byte 0x030046A0
_080EA0A0:
	cmp r1, #0
	bge _080EA0A6
	movs r1, #0
_080EA0A6:
	ldr r2, _080EA0B4 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080EA0B4: .4byte 0x030046A0
_080EA0B8:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080EA100
	ldr r1, _080EA0DC @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EA0E0 @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA0E4 @ =0x0000270F
	cmp r1, r0
	ble _080EA0E8
	adds r1, r0, #0
	b _080EA0EE
	.align 2, 0
_080EA0DC: .4byte 0x030046A0
_080EA0E0: .4byte 0x0000022A
_080EA0E4: .4byte 0x0000270F
_080EA0E8:
	cmp r1, #0
	bge _080EA0EE
	movs r1, #0
_080EA0EE:
	ldr r2, _080EA0F8 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EA0FC @ =0x0000022A
	bl _080EAFCE
	.align 2, 0
_080EA0F8: .4byte 0x030046A0
_080EA0FC: .4byte 0x0000022A
_080EA100:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080EA144
	ldr r1, _080EA124 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA128 @ =0x0000270F
	cmp r1, r0
	ble _080EA12C
	adds r1, r0, #0
	b _080EA132
	.align 2, 0
_080EA124: .4byte 0x030046A0
_080EA128: .4byte 0x0000270F
_080EA12C:
	cmp r1, #0
	bge _080EA132
	movs r1, #0
_080EA132:
	ldr r2, _080EA140 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080EA140: .4byte 0x030046A0
_080EA144:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080EA152
	bl _080E9350
_080EA152:
	ldr r1, _080EA16C @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EA170 @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA174 @ =0x0000270F
	cmp r1, r0
	ble _080EA178
	adds r1, r0, #0
	b _080EA17E
	.align 2, 0
_080EA16C: .4byte 0x030046A0
_080EA170: .4byte 0x0000022E
_080EA174: .4byte 0x0000270F
_080EA178:
	cmp r1, #0
	bge _080EA17E
	movs r1, #0
_080EA17E:
	ldr r2, _080EA188 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EA18C @ =0x0000022E
	bl _080EAFCE
	.align 2, 0
_080EA188: .4byte 0x030046A0
_080EA18C: .4byte 0x0000022E
_080EA190:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080EA1B0 @ =0x030046A0
	ldr r0, [r2]
	adds r1, #0xfe
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080EA1B4 @ =0x0000270E
	cmp r1, r0
	bgt _080EA1B8
	adds r0, r5, #1
	b _080EA1BC
	.align 2, 0
_080EA1B0: .4byte 0x030046A0
_080EA1B4: .4byte 0x0000270E
_080EA1B8:
	ldr r1, _080EA1E0 @ =0x0000270F
	adds r0, r1, #0
_080EA1BC:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080EA200
	ldr r2, _080EA1E4 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080EA1E0 @ =0x0000270F
	cmp r1, r0
	ble _080EA1E8
	adds r1, r0, #0
	b _080EA1EE
	.align 2, 0
_080EA1E0: .4byte 0x0000270F
_080EA1E4: .4byte 0x030046A0
_080EA1E8:
	cmp r1, #0
	bge _080EA1EE
	movs r1, #0
_080EA1EE:
	ldr r2, _080EA1FC @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080EA1FC: .4byte 0x030046A0
_080EA200:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080EA248
	ldr r1, _080EA224 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EA228 @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA22C @ =0x0000270F
	cmp r1, r0
	ble _080EA230
	adds r1, r0, #0
	b _080EA236
	.align 2, 0
_080EA224: .4byte 0x030046A0
_080EA228: .4byte 0x0000022A
_080EA22C: .4byte 0x0000270F
_080EA230:
	cmp r1, #0
	bge _080EA236
	movs r1, #0
_080EA236:
	ldr r2, _080EA240 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EA244 @ =0x0000022A
	bl _080EAFCE
	.align 2, 0
_080EA240: .4byte 0x030046A0
_080EA244: .4byte 0x0000022A
_080EA248:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080EA28C
	ldr r1, _080EA26C @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA270 @ =0x0000270F
	cmp r1, r0
	ble _080EA274
	adds r1, r0, #0
	b _080EA27A
	.align 2, 0
_080EA26C: .4byte 0x030046A0
_080EA270: .4byte 0x0000270F
_080EA274:
	cmp r1, #0
	bge _080EA27A
	movs r1, #0
_080EA27A:
	ldr r2, _080EA288 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080EA288: .4byte 0x030046A0
_080EA28C:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080EA29A
	bl _080E9350
_080EA29A:
	ldr r1, _080EA2B4 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EA2B8 @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA2BC @ =0x0000270F
	cmp r1, r0
	ble _080EA2C0
	adds r1, r0, #0
	b _080EA2C6
	.align 2, 0
_080EA2B4: .4byte 0x030046A0
_080EA2B8: .4byte 0x0000022E
_080EA2BC: .4byte 0x0000270F
_080EA2C0:
	cmp r1, #0
	bge _080EA2C6
	movs r1, #0
_080EA2C6:
	ldr r2, _080EA2D0 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EA2D4 @ =0x0000022E
	bl _080EAFCE
	.align 2, 0
_080EA2D0: .4byte 0x030046A0
_080EA2D4: .4byte 0x0000022E
_080EA2D8:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080EA2FC @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x84
	lsls r1, r1, #2
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080EA300 @ =0x0000270E
	cmp r1, r0
	bgt _080EA304
	adds r0, r5, #1
	b _080EA308
	.align 2, 0
_080EA2FC: .4byte 0x030046A0
_080EA300: .4byte 0x0000270E
_080EA304:
	ldr r1, _080EA32C @ =0x0000270F
	adds r0, r1, #0
_080EA308:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080EA34C
	ldr r2, _080EA330 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080EA32C @ =0x0000270F
	cmp r1, r0
	ble _080EA334
	adds r1, r0, #0
	b _080EA33A
	.align 2, 0
_080EA32C: .4byte 0x0000270F
_080EA330: .4byte 0x030046A0
_080EA334:
	cmp r1, #0
	bge _080EA33A
	movs r1, #0
_080EA33A:
	ldr r2, _080EA348 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080EA348: .4byte 0x030046A0
_080EA34C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080EA394
	ldr r1, _080EA370 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EA374 @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA378 @ =0x0000270F
	cmp r1, r0
	ble _080EA37C
	adds r1, r0, #0
	b _080EA382
	.align 2, 0
_080EA370: .4byte 0x030046A0
_080EA374: .4byte 0x0000022A
_080EA378: .4byte 0x0000270F
_080EA37C:
	cmp r1, #0
	bge _080EA382
	movs r1, #0
_080EA382:
	ldr r2, _080EA38C @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EA390 @ =0x0000022A
	bl _080EAFCE
	.align 2, 0
_080EA38C: .4byte 0x030046A0
_080EA390: .4byte 0x0000022A
_080EA394:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080EA3D8
	ldr r1, _080EA3B8 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA3BC @ =0x0000270F
	cmp r1, r0
	ble _080EA3C0
	adds r1, r0, #0
	b _080EA3C6
	.align 2, 0
_080EA3B8: .4byte 0x030046A0
_080EA3BC: .4byte 0x0000270F
_080EA3C0:
	cmp r1, #0
	bge _080EA3C6
	movs r1, #0
_080EA3C6:
	ldr r2, _080EA3D4 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080EA3D4: .4byte 0x030046A0
_080EA3D8:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080EA3E6
	bl _080E9350
_080EA3E6:
	ldr r1, _080EA400 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EA404 @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA408 @ =0x0000270F
	cmp r1, r0
	ble _080EA40C
	adds r1, r0, #0
	b _080EA412
	.align 2, 0
_080EA400: .4byte 0x030046A0
_080EA404: .4byte 0x0000022E
_080EA408: .4byte 0x0000270F
_080EA40C:
	cmp r1, #0
	bge _080EA412
	movs r1, #0
_080EA412:
	ldr r2, _080EA41C @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EA420 @ =0x0000022E
	bl _080EAFCE
	.align 2, 0
_080EA41C: .4byte 0x030046A0
_080EA420: .4byte 0x0000022E
_080EA424:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080EA444 @ =0x030046A0
	ldr r0, [r2]
	adds r1, #0xfc
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080EA448 @ =0x0000270E
	cmp r1, r0
	bgt _080EA44C
	adds r0, r5, #1
	b _080EA450
	.align 2, 0
_080EA444: .4byte 0x030046A0
_080EA448: .4byte 0x0000270E
_080EA44C:
	ldr r1, _080EA474 @ =0x0000270F
	adds r0, r1, #0
_080EA450:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080EA494
	ldr r2, _080EA478 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080EA474 @ =0x0000270F
	cmp r1, r0
	ble _080EA47C
	adds r1, r0, #0
	b _080EA482
	.align 2, 0
_080EA474: .4byte 0x0000270F
_080EA478: .4byte 0x030046A0
_080EA47C:
	cmp r1, #0
	bge _080EA482
	movs r1, #0
_080EA482:
	ldr r2, _080EA490 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080EA490: .4byte 0x030046A0
_080EA494:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080EA4DC
	ldr r1, _080EA4B8 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EA4BC @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA4C0 @ =0x0000270F
	cmp r1, r0
	ble _080EA4C4
	adds r1, r0, #0
	b _080EA4CA
	.align 2, 0
_080EA4B8: .4byte 0x030046A0
_080EA4BC: .4byte 0x0000022A
_080EA4C0: .4byte 0x0000270F
_080EA4C4:
	cmp r1, #0
	bge _080EA4CA
	movs r1, #0
_080EA4CA:
	ldr r2, _080EA4D4 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EA4D8 @ =0x0000022A
	bl _080EAFCE
	.align 2, 0
_080EA4D4: .4byte 0x030046A0
_080EA4D8: .4byte 0x0000022A
_080EA4DC:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080EA520
	ldr r1, _080EA500 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA504 @ =0x0000270F
	cmp r1, r0
	ble _080EA508
	adds r1, r0, #0
	b _080EA50E
	.align 2, 0
_080EA500: .4byte 0x030046A0
_080EA504: .4byte 0x0000270F
_080EA508:
	cmp r1, #0
	bge _080EA50E
	movs r1, #0
_080EA50E:
	ldr r2, _080EA51C @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080EA51C: .4byte 0x030046A0
_080EA520:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080EA52E
	bl _080E9350
_080EA52E:
	ldr r1, _080EA548 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EA54C @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA550 @ =0x0000270F
	cmp r1, r0
	ble _080EA554
	adds r1, r0, #0
	b _080EA55A
	.align 2, 0
_080EA548: .4byte 0x030046A0
_080EA54C: .4byte 0x0000022E
_080EA550: .4byte 0x0000270F
_080EA554:
	cmp r1, #0
	bge _080EA55A
	movs r1, #0
_080EA55A:
	ldr r2, _080EA564 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EA568 @ =0x0000022E
	bl _080EAFCE
	.align 2, 0
_080EA564: .4byte 0x030046A0
_080EA568: .4byte 0x0000022E
_080EA56C:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080EA590 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x85
	lsls r1, r1, #2
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080EA594 @ =0x0000270E
	cmp r1, r0
	bgt _080EA598
	adds r0, r5, #1
	b _080EA59C
	.align 2, 0
_080EA590: .4byte 0x030046A0
_080EA594: .4byte 0x0000270E
_080EA598:
	ldr r1, _080EA5C0 @ =0x0000270F
	adds r0, r1, #0
_080EA59C:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080EA5E0
	ldr r2, _080EA5C4 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080EA5C0 @ =0x0000270F
	cmp r1, r0
	ble _080EA5C8
	adds r1, r0, #0
	b _080EA5CE
	.align 2, 0
_080EA5C0: .4byte 0x0000270F
_080EA5C4: .4byte 0x030046A0
_080EA5C8:
	cmp r1, #0
	bge _080EA5CE
	movs r1, #0
_080EA5CE:
	ldr r2, _080EA5DC @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080EA5DC: .4byte 0x030046A0
_080EA5E0:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080EA628
	ldr r1, _080EA604 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EA608 @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA60C @ =0x0000270F
	cmp r1, r0
	ble _080EA610
	adds r1, r0, #0
	b _080EA616
	.align 2, 0
_080EA604: .4byte 0x030046A0
_080EA608: .4byte 0x0000022A
_080EA60C: .4byte 0x0000270F
_080EA610:
	cmp r1, #0
	bge _080EA616
	movs r1, #0
_080EA616:
	ldr r2, _080EA620 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EA624 @ =0x0000022A
	bl _080EAFCE
	.align 2, 0
_080EA620: .4byte 0x030046A0
_080EA624: .4byte 0x0000022A
_080EA628:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080EA66C
	ldr r1, _080EA64C @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA650 @ =0x0000270F
	cmp r1, r0
	ble _080EA654
	adds r1, r0, #0
	b _080EA65A
	.align 2, 0
_080EA64C: .4byte 0x030046A0
_080EA650: .4byte 0x0000270F
_080EA654:
	cmp r1, #0
	bge _080EA65A
	movs r1, #0
_080EA65A:
	ldr r2, _080EA668 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080EA668: .4byte 0x030046A0
_080EA66C:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080EA67A
	bl _080E9350
_080EA67A:
	ldr r1, _080EA694 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EA698 @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA69C @ =0x0000270F
	cmp r1, r0
	ble _080EA6A0
	adds r1, r0, #0
	b _080EA6A6
	.align 2, 0
_080EA694: .4byte 0x030046A0
_080EA698: .4byte 0x0000022E
_080EA69C: .4byte 0x0000270F
_080EA6A0:
	cmp r1, #0
	bge _080EA6A6
	movs r1, #0
_080EA6A6:
	ldr r2, _080EA6B0 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EA6B4 @ =0x0000022E
	bl _080EAFCE
	.align 2, 0
_080EA6B0: .4byte 0x030046A0
_080EA6B4: .4byte 0x0000022E
_080EA6B8:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080EA6D8 @ =0x030046A0
	ldr r0, [r2]
	ldr r1, _080EA6DC @ =0x00000216
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080EA6E0 @ =0x0000270E
	cmp r1, r0
	bgt _080EA6E4
	adds r0, r5, #1
	b _080EA6E8
	.align 2, 0
_080EA6D8: .4byte 0x030046A0
_080EA6DC: .4byte 0x00000216
_080EA6E0: .4byte 0x0000270E
_080EA6E4:
	ldr r1, _080EA70C @ =0x0000270F
	adds r0, r1, #0
_080EA6E8:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080EA72C
	ldr r2, _080EA710 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080EA70C @ =0x0000270F
	cmp r1, r0
	ble _080EA714
	adds r1, r0, #0
	b _080EA71A
	.align 2, 0
_080EA70C: .4byte 0x0000270F
_080EA710: .4byte 0x030046A0
_080EA714:
	cmp r1, #0
	bge _080EA71A
	movs r1, #0
_080EA71A:
	ldr r2, _080EA728 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080EA728: .4byte 0x030046A0
_080EA72C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080EA774
	ldr r1, _080EA750 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EA754 @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA758 @ =0x0000270F
	cmp r1, r0
	ble _080EA75C
	adds r1, r0, #0
	b _080EA762
	.align 2, 0
_080EA750: .4byte 0x030046A0
_080EA754: .4byte 0x0000022A
_080EA758: .4byte 0x0000270F
_080EA75C:
	cmp r1, #0
	bge _080EA762
	movs r1, #0
_080EA762:
	ldr r2, _080EA76C @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EA770 @ =0x0000022A
	bl _080EAFCE
	.align 2, 0
_080EA76C: .4byte 0x030046A0
_080EA770: .4byte 0x0000022A
_080EA774:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080EA7B8
	ldr r1, _080EA798 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA79C @ =0x0000270F
	cmp r1, r0
	ble _080EA7A0
	adds r1, r0, #0
	b _080EA7A6
	.align 2, 0
_080EA798: .4byte 0x030046A0
_080EA79C: .4byte 0x0000270F
_080EA7A0:
	cmp r1, #0
	bge _080EA7A6
	movs r1, #0
_080EA7A6:
	ldr r2, _080EA7B4 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080EA7B4: .4byte 0x030046A0
_080EA7B8:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080EA7C6
	bl _080E9350
_080EA7C6:
	ldr r1, _080EA7E0 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EA7E4 @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA7E8 @ =0x0000270F
	cmp r1, r0
	ble _080EA7EC
	adds r1, r0, #0
	b _080EA7F2
	.align 2, 0
_080EA7E0: .4byte 0x030046A0
_080EA7E4: .4byte 0x0000022E
_080EA7E8: .4byte 0x0000270F
_080EA7EC:
	cmp r1, #0
	bge _080EA7F2
	movs r1, #0
_080EA7F2:
	ldr r2, _080EA7FC @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EA800 @ =0x0000022E
	bl _080EAFCE
	.align 2, 0
_080EA7FC: .4byte 0x030046A0
_080EA800: .4byte 0x0000022E
_080EA804:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080EA824 @ =0x030046A0
	ldr r0, [r2]
	adds r1, #0xee
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080EA828 @ =0x0000270E
	cmp r1, r0
	bgt _080EA82C
	adds r0, r5, #1
	b _080EA830
	.align 2, 0
_080EA824: .4byte 0x030046A0
_080EA828: .4byte 0x0000270E
_080EA82C:
	ldr r1, _080EA854 @ =0x0000270F
	adds r0, r1, #0
_080EA830:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080EA874
	ldr r2, _080EA858 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080EA854 @ =0x0000270F
	cmp r1, r0
	ble _080EA85C
	adds r1, r0, #0
	b _080EA862
	.align 2, 0
_080EA854: .4byte 0x0000270F
_080EA858: .4byte 0x030046A0
_080EA85C:
	cmp r1, #0
	bge _080EA862
	movs r1, #0
_080EA862:
	ldr r2, _080EA870 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	bl _080EAFCE
	.align 2, 0
_080EA870: .4byte 0x030046A0
_080EA874:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080EA8BC
	ldr r1, _080EA898 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EA89C @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA8A0 @ =0x0000270F
	cmp r1, r0
	ble _080EA8A4
	adds r1, r0, #0
	b _080EA8AA
	.align 2, 0
_080EA898: .4byte 0x030046A0
_080EA89C: .4byte 0x0000022A
_080EA8A0: .4byte 0x0000270F
_080EA8A4:
	cmp r1, #0
	bge _080EA8AA
	movs r1, #0
_080EA8AA:
	ldr r2, _080EA8B4 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EA8B8 @ =0x0000022A
	b _080EAFCE
	.align 2, 0
_080EA8B4: .4byte 0x030046A0
_080EA8B8: .4byte 0x0000022A
_080EA8BC:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080EA8FC
	ldr r1, _080EA8E0 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA8E4 @ =0x0000270F
	cmp r1, r0
	ble _080EA8E8
	adds r1, r0, #0
	b _080EA8EE
	.align 2, 0
_080EA8E0: .4byte 0x030046A0
_080EA8E4: .4byte 0x0000270F
_080EA8E8:
	cmp r1, #0
	bge _080EA8EE
	movs r1, #0
_080EA8EE:
	ldr r2, _080EA8F8 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	b _080EAFCE
	.align 2, 0
_080EA8F8: .4byte 0x030046A0
_080EA8FC:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080EA90A
	bl _080E9350
_080EA90A:
	ldr r1, _080EA924 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EA928 @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA92C @ =0x0000270F
	cmp r1, r0
	ble _080EA930
	adds r1, r0, #0
	b _080EA936
	.align 2, 0
_080EA924: .4byte 0x030046A0
_080EA928: .4byte 0x0000022E
_080EA92C: .4byte 0x0000270F
_080EA930:
	cmp r1, #0
	bge _080EA936
	movs r1, #0
_080EA936:
	ldr r2, _080EA940 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EA944 @ =0x0000022E
	b _080EAFCE
	.align 2, 0
_080EA940: .4byte 0x030046A0
_080EA944: .4byte 0x0000022E
_080EA948:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080EA968 @ =0x030046A0
	ldr r0, [r2]
	ldr r1, _080EA96C @ =0x0000021A
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080EA970 @ =0x0000270E
	cmp r1, r0
	bgt _080EA974
	adds r0, r5, #1
	b _080EA978
	.align 2, 0
_080EA968: .4byte 0x030046A0
_080EA96C: .4byte 0x0000021A
_080EA970: .4byte 0x0000270E
_080EA974:
	ldr r1, _080EA99C @ =0x0000270F
	adds r0, r1, #0
_080EA978:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080EA9B8
	ldr r2, _080EA9A0 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080EA99C @ =0x0000270F
	cmp r1, r0
	ble _080EA9A4
	adds r1, r0, #0
	b _080EA9AA
	.align 2, 0
_080EA99C: .4byte 0x0000270F
_080EA9A0: .4byte 0x030046A0
_080EA9A4:
	cmp r1, #0
	bge _080EA9AA
	movs r1, #0
_080EA9AA:
	ldr r2, _080EA9B4 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	b _080EAFCE
	.align 2, 0
_080EA9B4: .4byte 0x030046A0
_080EA9B8:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080EAA00
	ldr r1, _080EA9DC @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EA9E0 @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EA9E4 @ =0x0000270F
	cmp r1, r0
	ble _080EA9E8
	adds r1, r0, #0
	b _080EA9EE
	.align 2, 0
_080EA9DC: .4byte 0x030046A0
_080EA9E0: .4byte 0x0000022A
_080EA9E4: .4byte 0x0000270F
_080EA9E8:
	cmp r1, #0
	bge _080EA9EE
	movs r1, #0
_080EA9EE:
	ldr r2, _080EA9F8 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EA9FC @ =0x0000022A
	b _080EAFCE
	.align 2, 0
_080EA9F8: .4byte 0x030046A0
_080EA9FC: .4byte 0x0000022A
_080EAA00:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080EAA40
	ldr r1, _080EAA24 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EAA28 @ =0x0000270F
	cmp r1, r0
	ble _080EAA2C
	adds r1, r0, #0
	b _080EAA32
	.align 2, 0
_080EAA24: .4byte 0x030046A0
_080EAA28: .4byte 0x0000270F
_080EAA2C:
	cmp r1, #0
	bge _080EAA32
	movs r1, #0
_080EAA32:
	ldr r2, _080EAA3C @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	b _080EAFCE
	.align 2, 0
_080EAA3C: .4byte 0x030046A0
_080EAA40:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080EAA4E
	bl _080E9350
_080EAA4E:
	ldr r1, _080EAA68 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EAA6C @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EAA70 @ =0x0000270F
	cmp r1, r0
	ble _080EAA74
	adds r1, r0, #0
	b _080EAA7A
	.align 2, 0
_080EAA68: .4byte 0x030046A0
_080EAA6C: .4byte 0x0000022E
_080EAA70: .4byte 0x0000270F
_080EAA74:
	cmp r1, #0
	bge _080EAA7A
	movs r1, #0
_080EAA7A:
	ldr r2, _080EAA84 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EAA88 @ =0x0000022E
	b _080EAFCE
	.align 2, 0
_080EAA84: .4byte 0x030046A0
_080EAA88: .4byte 0x0000022E
_080EAA8C:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080EAAB0 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080EAAB4 @ =0x0000270E
	cmp r1, r0
	bgt _080EAAB8
	adds r0, r5, #1
	b _080EAABC
	.align 2, 0
_080EAAB0: .4byte 0x030046A0
_080EAAB4: .4byte 0x0000270E
_080EAAB8:
	ldr r1, _080EAAE0 @ =0x0000270F
	adds r0, r1, #0
_080EAABC:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080EAAFC
	ldr r2, _080EAAE4 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080EAAE0 @ =0x0000270F
	cmp r1, r0
	ble _080EAAE8
	adds r1, r0, #0
	b _080EAAEE
	.align 2, 0
_080EAAE0: .4byte 0x0000270F
_080EAAE4: .4byte 0x030046A0
_080EAAE8:
	cmp r1, #0
	bge _080EAAEE
	movs r1, #0
_080EAAEE:
	ldr r2, _080EAAF8 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	b _080EAFCE
	.align 2, 0
_080EAAF8: .4byte 0x030046A0
_080EAAFC:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080EAB44
	ldr r1, _080EAB20 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EAB24 @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EAB28 @ =0x0000270F
	cmp r1, r0
	ble _080EAB2C
	adds r1, r0, #0
	b _080EAB32
	.align 2, 0
_080EAB20: .4byte 0x030046A0
_080EAB24: .4byte 0x0000022A
_080EAB28: .4byte 0x0000270F
_080EAB2C:
	cmp r1, #0
	bge _080EAB32
	movs r1, #0
_080EAB32:
	ldr r2, _080EAB3C @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EAB40 @ =0x0000022A
	b _080EAFCE
	.align 2, 0
_080EAB3C: .4byte 0x030046A0
_080EAB40: .4byte 0x0000022A
_080EAB44:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080EAB84
	ldr r1, _080EAB68 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EAB6C @ =0x0000270F
	cmp r1, r0
	ble _080EAB70
	adds r1, r0, #0
	b _080EAB76
	.align 2, 0
_080EAB68: .4byte 0x030046A0
_080EAB6C: .4byte 0x0000270F
_080EAB70:
	cmp r1, #0
	bge _080EAB76
	movs r1, #0
_080EAB76:
	ldr r2, _080EAB80 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	b _080EAFCE
	.align 2, 0
_080EAB80: .4byte 0x030046A0
_080EAB84:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080EAB92
	bl _080E9350
_080EAB92:
	ldr r1, _080EABAC @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EABB0 @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EABB4 @ =0x0000270F
	cmp r1, r0
	ble _080EABB8
	adds r1, r0, #0
	b _080EABBE
	.align 2, 0
_080EABAC: .4byte 0x030046A0
_080EABB0: .4byte 0x0000022E
_080EABB4: .4byte 0x0000270F
_080EABB8:
	cmp r1, #0
	bge _080EABBE
	movs r1, #0
_080EABBE:
	ldr r2, _080EABC8 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EABCC @ =0x0000022E
	b _080EAFCE
	.align 2, 0
_080EABC8: .4byte 0x030046A0
_080EABCC: .4byte 0x0000022E
_080EABD0:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080EABF4 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x86
	lsls r1, r1, #2
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080EABF8 @ =0x0000270E
	cmp r1, r0
	bgt _080EABFC
	adds r0, r5, #1
	b _080EAC00
	.align 2, 0
_080EABF4: .4byte 0x030046A0
_080EABF8: .4byte 0x0000270E
_080EABFC:
	ldr r1, _080EAC24 @ =0x0000270F
	adds r0, r1, #0
_080EAC00:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080EAC40
	ldr r2, _080EAC28 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080EAC24 @ =0x0000270F
	cmp r1, r0
	ble _080EAC2C
	adds r1, r0, #0
	b _080EAC32
	.align 2, 0
_080EAC24: .4byte 0x0000270F
_080EAC28: .4byte 0x030046A0
_080EAC2C:
	cmp r1, #0
	bge _080EAC32
	movs r1, #0
_080EAC32:
	ldr r2, _080EAC3C @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	b _080EAFCE
	.align 2, 0
_080EAC3C: .4byte 0x030046A0
_080EAC40:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080EAC88
	ldr r1, _080EAC64 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EAC68 @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EAC6C @ =0x0000270F
	cmp r1, r0
	ble _080EAC70
	adds r1, r0, #0
	b _080EAC76
	.align 2, 0
_080EAC64: .4byte 0x030046A0
_080EAC68: .4byte 0x0000022A
_080EAC6C: .4byte 0x0000270F
_080EAC70:
	cmp r1, #0
	bge _080EAC76
	movs r1, #0
_080EAC76:
	ldr r2, _080EAC80 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EAC84 @ =0x0000022A
	b _080EAFCE
	.align 2, 0
_080EAC80: .4byte 0x030046A0
_080EAC84: .4byte 0x0000022A
_080EAC88:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080EACC8
	ldr r1, _080EACAC @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EACB0 @ =0x0000270F
	cmp r1, r0
	ble _080EACB4
	adds r1, r0, #0
	b _080EACBA
	.align 2, 0
_080EACAC: .4byte 0x030046A0
_080EACB0: .4byte 0x0000270F
_080EACB4:
	cmp r1, #0
	bge _080EACBA
	movs r1, #0
_080EACBA:
	ldr r2, _080EACC4 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	b _080EAFCE
	.align 2, 0
_080EACC4: .4byte 0x030046A0
_080EACC8:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080EACD6
	bl _080E9350
_080EACD6:
	ldr r1, _080EACF0 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EACF4 @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EACF8 @ =0x0000270F
	cmp r1, r0
	ble _080EACFC
	adds r1, r0, #0
	b _080EAD02
	.align 2, 0
_080EACF0: .4byte 0x030046A0
_080EACF4: .4byte 0x0000022E
_080EACF8: .4byte 0x0000270F
_080EACFC:
	cmp r1, #0
	bge _080EAD02
	movs r1, #0
_080EAD02:
	ldr r2, _080EAD0C @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EAD10 @ =0x0000022E
	b _080EAFCE
	.align 2, 0
_080EAD0C: .4byte 0x030046A0
_080EAD10: .4byte 0x0000022E
_080EAD14:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080EAD34 @ =0x030046A0
	ldr r0, [r2]
	adds r1, #0xf6
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080EAD38 @ =0x0000270E
	cmp r1, r0
	bgt _080EAD3C
	adds r0, r5, #1
	b _080EAD40
	.align 2, 0
_080EAD34: .4byte 0x030046A0
_080EAD38: .4byte 0x0000270E
_080EAD3C:
	ldr r1, _080EAD64 @ =0x0000270F
	adds r0, r1, #0
_080EAD40:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080EAD80
	ldr r2, _080EAD68 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080EAD64 @ =0x0000270F
	cmp r1, r0
	ble _080EAD6C
	adds r1, r0, #0
	b _080EAD72
	.align 2, 0
_080EAD64: .4byte 0x0000270F
_080EAD68: .4byte 0x030046A0
_080EAD6C:
	cmp r1, #0
	bge _080EAD72
	movs r1, #0
_080EAD72:
	ldr r2, _080EAD7C @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	b _080EAFCE
	.align 2, 0
_080EAD7C: .4byte 0x030046A0
_080EAD80:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080EADC8
	ldr r1, _080EADA4 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EADA8 @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EADAC @ =0x0000270F
	cmp r1, r0
	ble _080EADB0
	adds r1, r0, #0
	b _080EADB6
	.align 2, 0
_080EADA4: .4byte 0x030046A0
_080EADA8: .4byte 0x0000022A
_080EADAC: .4byte 0x0000270F
_080EADB0:
	cmp r1, #0
	bge _080EADB6
	movs r1, #0
_080EADB6:
	ldr r2, _080EADC0 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EADC4 @ =0x0000022A
	b _080EAFCE
	.align 2, 0
_080EADC0: .4byte 0x030046A0
_080EADC4: .4byte 0x0000022A
_080EADC8:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080EAE08
	ldr r1, _080EADEC @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EADF0 @ =0x0000270F
	cmp r1, r0
	ble _080EADF4
	adds r1, r0, #0
	b _080EADFA
	.align 2, 0
_080EADEC: .4byte 0x030046A0
_080EADF0: .4byte 0x0000270F
_080EADF4:
	cmp r1, #0
	bge _080EADFA
	movs r1, #0
_080EADFA:
	ldr r2, _080EAE04 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	b _080EAFCE
	.align 2, 0
_080EAE04: .4byte 0x030046A0
_080EAE08:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	bne _080EAE16
	bl _080E9350
_080EAE16:
	ldr r1, _080EAE30 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EAE34 @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EAE38 @ =0x0000270F
	cmp r1, r0
	ble _080EAE3C
	adds r1, r0, #0
	b _080EAE42
	.align 2, 0
_080EAE30: .4byte 0x030046A0
_080EAE34: .4byte 0x0000022E
_080EAE38: .4byte 0x0000270F
_080EAE3C:
	cmp r1, #0
	bge _080EAE42
	movs r1, #0
_080EAE42:
	ldr r2, _080EAE4C @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EAE50 @ =0x0000022E
	b _080EAFCE
	.align 2, 0
_080EAE4C: .4byte 0x030046A0
_080EAE50: .4byte 0x0000022E
_080EAE54:
	movs r1, #0x88
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r4, [r0]
	ldr r2, _080EAE74 @ =0x030046A0
	ldr r0, [r2]
	ldr r1, _080EAE78 @ =0x0000021E
	adds r3, r0, r1
	ldrh r5, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _080EAE7C @ =0x0000270E
	cmp r1, r0
	bgt _080EAE80
	adds r0, r5, #1
	b _080EAE84
	.align 2, 0
_080EAE74: .4byte 0x030046A0
_080EAE78: .4byte 0x0000021E
_080EAE7C: .4byte 0x0000270E
_080EAE80:
	ldr r1, _080EAEA8 @ =0x0000270F
	adds r0, r1, #0
_080EAE84:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080EAEC4
	ldr r2, _080EAEAC @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0x8a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #1
	ldr r0, _080EAEA8 @ =0x0000270F
	cmp r1, r0
	ble _080EAEB0
	adds r1, r0, #0
	b _080EAEB6
	.align 2, 0
_080EAEA8: .4byte 0x0000270F
_080EAEAC: .4byte 0x030046A0
_080EAEB0:
	cmp r1, #0
	bge _080EAEB6
	movs r1, #0
_080EAEB6:
	ldr r2, _080EAEC0 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8a
	lsls r2, r2, #2
	b _080EAFCE
	.align 2, 0
_080EAEC0: .4byte 0x030046A0
_080EAEC4:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r4
	cmp r0, #0
	beq _080EAF0C
	ldr r1, _080EAEE8 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EAEEC @ =0x0000022A
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EAEF0 @ =0x0000270F
	cmp r1, r0
	ble _080EAEF4
	adds r1, r0, #0
	b _080EAEFA
	.align 2, 0
_080EAEE8: .4byte 0x030046A0
_080EAEEC: .4byte 0x0000022A
_080EAEF0: .4byte 0x0000270F
_080EAEF4:
	cmp r1, #0
	bge _080EAEFA
	movs r1, #0
_080EAEFA:
	ldr r2, _080EAF04 @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EAF08 @ =0x0000022A
	b _080EAFCE
	.align 2, 0
_080EAF04: .4byte 0x030046A0
_080EAF08: .4byte 0x0000022A
_080EAF0C:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _080EAF4C
	ldr r1, _080EAF30 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EAF34 @ =0x0000270F
	cmp r1, r0
	ble _080EAF38
	adds r1, r0, #0
	b _080EAF3E
	.align 2, 0
_080EAF30: .4byte 0x030046A0
_080EAF34: .4byte 0x0000270F
_080EAF38:
	cmp r1, #0
	bge _080EAF3E
	movs r1, #0
_080EAF3E:
	ldr r2, _080EAF48 @ =0x030046A0
	ldr r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #2
	b _080EAFCE
	.align 2, 0
_080EAF48: .4byte 0x030046A0
_080EAF4C:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	beq _080EAF94
	ldr r1, _080EAF70 @ =0x030046A0
	ldr r0, [r1]
	ldr r2, _080EAF74 @ =0x0000022E
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EAF78 @ =0x0000270F
	cmp r1, r0
	ble _080EAF7C
	adds r1, r0, #0
	b _080EAF82
	.align 2, 0
_080EAF70: .4byte 0x030046A0
_080EAF74: .4byte 0x0000022E
_080EAF78: .4byte 0x0000270F
_080EAF7C:
	cmp r1, #0
	bge _080EAF82
	movs r1, #0
_080EAF82:
	ldr r2, _080EAF8C @ =0x030046A0
	ldr r0, [r2]
	ldr r2, _080EAF90 @ =0x0000022E
	b _080EAFCE
	.align 2, 0
_080EAF8C: .4byte 0x030046A0
_080EAF90: .4byte 0x0000022E
_080EAF94:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r4, r0
	cmp r4, #0
	beq _080EAFD2
	ldr r1, _080EAFB8 @ =0x030046A0
	ldr r0, [r1]
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _080EAFBC @ =0x0000270F
	cmp r1, r0
	ble _080EAFC0
