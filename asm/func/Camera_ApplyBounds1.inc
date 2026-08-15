	push {r4, r5, lr}
	mov ip, r0
	ldrh r0, [r1, #2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	movs r2, #0
	ldrsh r0, [r1, r2]
	subs r2, r0, r4
	movs r3, #4
	ldrsh r0, [r1, r3]
	subs r3, r0, r4
	mov r0, ip
	adds r0, #0x8e
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r2, r0
	blt _0823B77E
	mov r0, ip
	adds r0, #0x92
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r2, r0
	ble _0823B780
_0823B77E:
	adds r2, r0, #0
_0823B780:
	mov r0, ip
	adds r0, #0x90
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r3, r0
	blt _0823B798
	mov r0, ip
	adds r0, #0x94
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r3, r0
	ble _0823B79A
_0823B798:
	adds r3, r0, #0
_0823B79A:
	adds r0, r2, r4
	strh r0, [r1]
	adds r0, r3, r4
	strh r0, [r1, #4]
	pop {r4, r5}
	pop {r0}
	bx r0
