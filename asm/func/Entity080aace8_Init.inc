	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	str r1, [r5, #0x18]
	movs r1, #0xd2
	lsls r1, r1, #2
	adds r0, r5, r1
	strh r2, [r0]
	ldr r0, [r5, #0x18]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, [sp]
	asrs r1, r2, #0x10
	adds r1, #0x96
	lsls r1, r1, #0x10
	ldr r0, _080AABF4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	adds r6, r5, #0
	adds r6, #0x84
	mov r7, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080AABF8
	asrs r0, r0, #8
	b _080AABFE
	.align 2, 0
_080AABF4: .4byte 0x0000FFFF
_080AABF8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080AABFE:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080AAC10
	asrs r0, r0, #8
	b _080AAC16
_080AAC10:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080AAC16:
	adds r4, r0, #0
	movs r2, #2
	ldrsh r1, [r7, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080AAC2A
	asrs r0, r0, #8
	b _080AAC30
_080AAC2A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080AAC30:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _080AAC74 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	adds r0, r5, #0
	bl FUN_080aa940
	adds r0, r5, #0
	bl FUN_080aaa2c
	adds r0, r5, #0
	bl FUN_080aaaa8
	ldr r1, [r5, #0x18]
	ldr r2, _080AAC78 @ =0x00000359
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080AAC7C
	adds r0, r1, #0
	adds r0, #0x90
	b _080AAC80
	.align 2, 0
_080AAC74: .4byte 0x030047C8
_080AAC78: .4byte 0x00000359
_080AAC7C:
	adds r0, r1, #0
	adds r0, #0xe8
_080AAC80:
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	ldr r0, [r5, #0x18]
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0
	strh r4, [r0]
	ldr r2, _080AACD8 @ =0x030047A4
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #4
	ldr r1, _080AACDC @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0xd2
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _080AACBC
	adds r0, r5, #0
	bl FUN_080aa9d0
_080AACBC:
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, _080AACE0 @ =FUN_080aa834
	str r1, [r0]
	ldr r2, _080AACE4 @ =0x0000034A
	adds r0, r5, r2
	strh r4, [r0]
	movs r0, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AACD8: .4byte 0x030047A4
_080AACDC: .4byte 0x030044BC
_080AACE0: .4byte FUN_080aa834
_080AACE4: .4byte 0x0000034A
