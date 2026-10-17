	push {r4, lr}
	mov ip, r0
	adds r4, r1, #0
	movs r0, #0xba
	lsls r0, r0, #2
	add r0, ip
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080CC29C @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080CC2A0
	asrs r0, r0, #0xc
	b _080CC2A6
	.align 2, 0
_080CC29C: .4byte gSineTable
_080CC2A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CC2A6:
	mov r1, ip
	strh r0, [r1, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _080CC2BC
	asrs r0, r0, #0xc
	b _080CC2C2
_080CC2BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CC2C2:
	mov r1, ip
	strh r0, [r1, #0x38]
	ldr r3, _080CC2E8 @ =0x000001C7
	add r3, ip
	ldrb r3, [r3]
	cmp r3, #1
	bne _080CC30A
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080CC2EC
	movs r2, #0x38
	ldrsh r1, [r1, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _080CC2FA
	b _080CC2FE
	.align 2, 0
_080CC2E8: .4byte 0x000001C7
_080CC2EC:
	mov r2, ip
	movs r0, #0x38
	ldrsh r1, [r2, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _080CC2FE
_080CC2FA:
	asrs r0, r0, #6
	b _080CC304
_080CC2FE:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_080CC304:
	mov r1, ip
	strh r0, [r1, #0x38]
	b _080CC342
_080CC30A:
	cmp r3, #2
	bne _080CC342
	mov r2, ip
	movs r1, #0x34
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bge _080CC326
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _080CC334
	b _080CC338
_080CC326:
	mov r2, ip
	movs r0, #0x34
	ldrsh r1, [r2, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _080CC338
_080CC334:
	asrs r0, r0, #6
	b _080CC33E
_080CC338:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_080CC33E:
	mov r1, ip
	strh r0, [r1, #0x34]
_080CC342:
	pop {r4}
	pop {r0}
	bx r0
