	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r7, #0
	str r7, [r6, #0x1c]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r6, r1
	strb r7, [r0]
	adds r0, r6, #0
	adds r0, #0x25
	strb r7, [r0]
	ldr r0, [r6, #0x1c]
	cmp r0, #0x38
	bls _0820FDBC
	str r7, [r6, #0x1c]
_0820FDBC:
	ldr r1, [r6, #0x1c]
	adds r0, r6, #0
	bl FUN_0820f9dc
	movs r3, #0xce
	lsls r3, r3, #2
	adds r5, r6, r3
	ldr r1, _0820FE3C @ =0x00001C1B
	adds r0, r5, #0
	bl Video_GetActorSprite
	movs r0, #0xc3
	lsls r0, r0, #2
	adds r4, r6, r0
	ldr r2, _0820FE40 @ =0x00000212
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0822a470
	movs r0, #5
	strh r0, [r4, #0x10]
	ldr r3, _0820FE44 @ =0x00000313
	adds r1, r6, r3
	movs r0, #3
	strb r0, [r1]
	movs r4, #0xd5
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r2, [r1]
	adds r3, #0x15
	adds r0, r6, r3
	strh r2, [r0]
	adds r4, #2
	adds r3, r6, r4
	ldrh r2, [r3]
	subs r4, #0x2c
	adds r0, r6, r4
	strh r2, [r0]
	ldrh r2, [r3]
	movs r3, #0xcb
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r2, [r0]
	subs r4, #0x16
	adds r2, r6, r4
	movs r0, #0x80
	strb r0, [r2]
	ldr r0, _0820FE48 @ =0x00000315
	adds r2, r6, r0
	movs r0, #0x40
	strb r0, [r2]
	str r7, [r6, #0x18]
	strh r7, [r6, #0x26]
	str r7, [sp]
	mov r0, sp
	ldr r2, _0820FE4C @ =0x05000002
	bl CpuSet
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0820FE3C: .4byte 0x00001C1B
_0820FE40: .4byte 0x00000212
_0820FE44: .4byte 0x00000313
_0820FE48: .4byte 0x00000315
_0820FE4C: .4byte 0x05000002
