	push {r4, r5, r6, r7, lr}
	bl FUN_0822d00c
	ldr r1, _0822D9DC @ =0x03004468
	str r0, [r1]
	movs r3, #0
	ldr r1, _0822D9E0 @ =0x03004458
	ldr r0, [r1]
	cmp r3, r0
	bge _0822D9D6
	ldr r0, _0822D9E4 @ =0x03003584
	mov ip, r0
	ldr r7, _0822D9E8 @ =0x03004470
	adds r6, r1, #0
	ldr r5, _0822D9EC @ =gObjectPlttBuffer
_0822D9AA:
	lsls r0, r3, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	lsls r0, r0, #5
	mov r2, ip
	ldr r1, [r2]
	adds r1, r1, r0
	lsls r0, r3, #5
	adds r2, r0, r5
	adds r4, r3, #1
	movs r3, #0xf
_0822D9C0:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _0822D9C0
	adds r3, r4, #0
	ldr r0, [r6]
	cmp r3, r0
	blt _0822D9AA
_0822D9D6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822D9DC: .4byte 0x03004468
_0822D9E0: .4byte 0x03004458
_0822D9E4: .4byte 0x03003584
_0822D9E8: .4byte 0x03004470
_0822D9EC: .4byte gObjectPlttBuffer
