	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0822D0A0 @ =0x03004044
	movs r1, #0
	str r1, [r0]
	ldr r0, _0822D0A4 @ =0x03004458
	str r1, [r0]
	ldr r0, _0822D0A8 @ =0x03004450
	str r1, [r0]
	ldr r3, _0822D0AC @ =gObjectPlttBuffer
	ldr r0, _0822D0B0 @ =0x03004468
	mov sl, r0
	ldr r7, _0822D0B4 @ =0x03004250
	ldr r0, _0822D0B8 @ =0x03004040
	mov ip, r0
	ldr r0, _0822D0BC @ =0x03004048
	mov r8, r0
	ldr r0, _0822D0C0 @ =0x03004460
	mov sb, r0
	movs r4, #0
	ldr r6, _0822D0C4 @ =0x03004470
	movs r5, #0
_0822D046:
	lsls r0, r1, #1
	adds r2, r1, #1
	movs r1, #0xf
_0822D04C:
	strh r4, [r3]
	adds r3, #2
	subs r1, #1
	cmp r1, #0
	bge _0822D04C
	adds r0, r0, r6
	strh r5, [r0]
	adds r1, r2, #0
	cmp r1, #0xf
	ble _0822D046
	mov r1, sl
	str r7, [r1]
	movs r0, #0x40
	mov r3, ip
	str r0, [r3]
	mov r1, r8
	str r0, [r1]
	mov r3, sb
	str r0, [r3]
	ldr r1, _0822D0C8 @ =0x00001084
	adds r2, r1, #0
	ldr r3, _0822D0CC @ =0x03004494
	strh r2, [r3]
	movs r1, #0
	ldr r3, _0822D0D0 @ =0x03004454
	strh r1, [r3]
	ldr r3, _0822D0D4 @ =0x0300445C
	str r0, [r3]
	ldr r3, _0822D0D8 @ =0x0300404C
	str r0, [r3]
	ldr r0, _0822D0DC @ =0x03004464
	strh r2, [r0]
	ldr r3, _0822D0E0 @ =0x03004490
	strh r1, [r3]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822D0A0: .4byte 0x03004044
_0822D0A4: .4byte 0x03004458
_0822D0A8: .4byte 0x03004450
_0822D0AC: .4byte gObjectPlttBuffer
_0822D0B0: .4byte 0x03004468
_0822D0B4: .4byte 0x03004250
_0822D0B8: .4byte 0x03004040
_0822D0BC: .4byte 0x03004048
_0822D0C0: .4byte 0x03004460
_0822D0C4: .4byte 0x03004470
_0822D0C8: .4byte 0x00001084
_0822D0CC: .4byte 0x03004494
_0822D0D0: .4byte 0x03004454
_0822D0D4: .4byte 0x0300445C
_0822D0D8: .4byte 0x0300404C
_0822D0DC: .4byte 0x03004464
_0822D0E0: .4byte 0x03004490
