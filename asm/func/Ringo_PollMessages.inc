	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	adds r5, r7, #0
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r0, r7, r0
	str r0, [sp]
	movs r1, #0
	mov sl, r1
	ldr r0, _0802A608 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0x8f
	lsls r2, r2, #1
	adds r0, r7, r2
	b _0802AB18
	.align 2, 0
_0802A608: .4byte 0x03002B4C
_0802A60C:
	ldr r0, _0802A640 @ =0x03002B4C
	ldr r0, [r0]
	mov r3, sl
	lsls r1, r3, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	ldr r0, [sp]
	adds r0, #8
	adds r0, r0, r1
	ldr r6, [r0]
	ldr r0, [sp]
	adds r1, r6, #0
	bl MsgQueue_BeginWait
	ldrb r0, [r6, #6]
	cmp r0, #0x20
	bls _0802A634
	b _0802AB0A
_0802A634:
	lsls r0, r0, #2
	ldr r1, _0802A644 @ =_0802A648
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802A640: .4byte 0x03002B4C
_0802A644: .4byte _0802A648
_0802A648: @ jump table
	.4byte _0802A6CC @ case 0
	.4byte _0802A710 @ case 1
	.4byte _0802A6E4 @ case 2
	.4byte _0802A758 @ case 3
	.4byte _0802A77A @ case 4
	.4byte _0802A7B8 @ case 5
	.4byte _0802A7E0 @ case 6
	.4byte _0802A808 @ case 7
	.4byte _0802A810 @ case 8
	.4byte _0802A818 @ case 9
	.4byte _0802AB0A @ case 10
	.4byte _0802A828 @ case 11
	.4byte _0802A830 @ case 12
	.4byte _0802A87C @ case 13
	.4byte _0802A924 @ case 14
	.4byte _0802A92C @ case 15
	.4byte _0802A968 @ case 16
	.4byte _0802A970 @ case 17
	.4byte _0802A998 @ case 18
	.4byte _0802A9A0 @ case 19
	.4byte _0802A9C8 @ case 20
	.4byte _0802A9D0 @ case 21
	.4byte _0802AB0A @ case 22
	.4byte _0802A9D8 @ case 23
	.4byte _0802A9E0 @ case 24
	.4byte _0802A9E8 @ case 25
	.4byte _0802A9F0 @ case 26
	.4byte _0802A9F8 @ case 27
	.4byte _0802AA00 @ case 28
	.4byte _0802AA08 @ case 29
	.4byte _0802AA4C @ case 30
	.4byte _0802AA10 @ case 31
	.4byte _0802AA32 @ case 32
_0802A6CC:
	movs r2, #2
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0xa4
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	b _0802AA28
_0802A6E4:
	ldrb r0, [r6, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r4, #0x8a
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r3, #0
	strb r0, [r1]
	movs r1, #2
	movs r2, #1
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r3, [r0]
	subs r0, #0x14
	strb r2, [r0]
	b _0802AB0A
_0802A710:
	ldrh r0, [r6, #8]
	adds r1, r7, #0
	adds r1, #0x50
	strh r0, [r1]
	ldrh r0, [r6, #0xa]
	adds r3, r7, #0
	adds r3, #0x52
	strh r0, [r3]
	ldrh r0, [r6, #0xc]
	adds r2, r7, #0
	adds r2, #0x54
	strh r0, [r2]
	ldrh r1, [r1]
	movs r4, #0xc5
	lsls r4, r4, #2
	adds r0, r5, r4
	strh r1, [r0]
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r3, [r3]
	adds r0, r0, r3
	ldr r3, _0802A754 @ =0x00000316
	adds r1, r5, r3
	strh r0, [r1]
	ldrh r1, [r2]
	adds r4, #4
	adds r0, r5, r4
	strh r1, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r7, r1
	b _0802AA40
	.align 2, 0
_0802A754: .4byte 0x00000316
_0802A758:
	ldrb r0, [r6, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r2, #0
	strb r0, [r1]
	movs r1, #2
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	b _0802AA24
_0802A77A:
	ldrh r1, [r6, #8]
	ldr r3, _0802A7B0 @ =0x0000084C
	adds r0, r5, r3
	movs r3, #0
	strh r1, [r0]
	ldrh r1, [r6, #0xa]
	ldr r4, _0802A7B4 @ =0x0000084E
	adds r0, r5, r4
	strh r1, [r0]
	ldrh r1, [r6, #0xc]
	movs r2, #0x85
	lsls r2, r2, #4
	adds r0, r5, r2
	strh r1, [r0]
	movs r1, #2
	movs r2, #3
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	movs r3, #0
	str r3, [r0]
	b _0802AA28
	.align 2, 0
_0802A7B0: .4byte 0x0000084C
_0802A7B4: .4byte 0x0000084E
_0802A7B8:
	ldrb r0, [r6, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r4, #0x8a
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r3, #0
	strb r0, [r1]
	movs r1, #2
	movs r2, #4
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r3, [r0]
	b _0802AA28
_0802A7E0:
	ldrb r0, [r6, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r3, #0
	strb r0, [r1]
	movs r1, #2
	movs r2, #5
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r3, [r0]
	b _0802AA28
_0802A808:
	movs r1, #2
	movs r2, #0
	movs r3, #6
	b _0802AA16
_0802A810:
	movs r1, #2
	movs r2, #0
	movs r3, #7
	b _0802AA16
_0802A818:
	movs r3, #8
	ldrsh r1, [r6, r3]
	adds r0, r7, #0
	movs r2, #0xb4
	movs r3, #0xb4
	bl Boss_ShowEmote
	b _0802AA3A
_0802A828:
	movs r1, #2
	movs r2, #0
	movs r3, #8
	b _0802AA16
_0802A830:
	ldrh r1, [r6, #8]
	ldr r2, _0802A870 @ =0x0000084C
	adds r0, r5, r2
	movs r4, #0
	strh r1, [r0]
	ldrh r1, [r6, #0xa]
	ldr r3, _0802A874 @ =0x0000084E
	adds r0, r5, r3
	strh r1, [r0]
	ldrh r1, [r6, #0xc]
	adds r2, #4
	adds r0, r5, r2
	strh r1, [r0]
	ldr r3, _0802A878 @ =0x00000171
	adds r0, r5, r3
	movs r3, #1
	strb r3, [r0]
	movs r1, #2
	movs r2, #9
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r4, [r0]
	subs r0, #0x14
	strb r3, [r0]
	b _0802AB0A
	.align 2, 0
_0802A870: .4byte 0x0000084C
_0802A874: .4byte 0x0000084E
_0802A878: .4byte 0x00000171
_0802A87C:
	ldrh r0, [r6, #8]
	ldr r2, _0802A91C @ =0x0000084C
	adds r3, r5, r2
	movs r4, #0
	mov r8, r4
	movs r1, #0
	mov sb, r1
	strh r0, [r3]
	ldrh r1, [r6, #0xa]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	ldrh r1, [r6, #0xc]
	movs r4, #0x85
	lsls r4, r4, #4
	adds r0, r5, r4
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x50
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r4, #0
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r3, r4]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	movs r4, #0x8a
	lsls r4, r4, #1
	adds r1, r7, r4
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	adds r3, r7, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa1
	strb r1, [r0]
	ldr r1, _0802A920 @ =0x00000171
	adds r0, r5, r1
	mov r2, r8
	strb r2, [r0]
	movs r1, #2
	movs r2, #9
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	mov r3, r8
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	mov r4, sb
	str r4, [r0]
	b _0802AA28
	.align 2, 0
_0802A91C: .4byte 0x0000084C
_0802A920: .4byte 0x00000171
_0802A924:
	movs r1, #2
	movs r2, #0
	movs r3, #0xa
	b _0802AA16
_0802A92C:
	ldrh r1, [r6, #8]
	ldr r2, _0802A960 @ =0x0000084C
	adds r0, r5, r2
	movs r3, #0
	strh r1, [r0]
	ldrh r1, [r6, #0xa]
	ldr r4, _0802A964 @ =0x0000084E
	adds r0, r5, r4
	strh r1, [r0]
	ldrh r1, [r6, #0xc]
	adds r2, #4
	adds r0, r5, r2
	strh r1, [r0]
	movs r1, #2
	movs r2, #0xb
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	movs r3, #0
	str r3, [r0]
	b _0802AA28
	.align 2, 0
_0802A960: .4byte 0x0000084C
_0802A964: .4byte 0x0000084E
_0802A968:
	movs r1, #2
	movs r2, #0
	movs r3, #0xc
	b _0802AA16
_0802A970:
	ldrh r1, [r6, #8]
	ldr r4, _0802A994 @ =0x000008CC
	adds r0, r5, r4
	movs r3, #0
	strb r1, [r0]
	movs r1, #2
	movs r2, #0xd
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r3, [r0]
	b _0802AA28
	.align 2, 0
_0802A994: .4byte 0x000008CC
_0802A998:
	movs r1, #2
	movs r2, #0
	movs r3, #0xe
	b _0802AA16
_0802A9A0:
	ldrh r0, [r6, #8]
	ldr r1, _0802A9C4 @ =0x0000018B
	adds r2, r5, r1
	movs r3, #0
	strb r0, [r2]
	movs r1, #2
	movs r2, #0xf
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r3, [r0]
	b _0802AA28
	.align 2, 0
_0802A9C4: .4byte 0x0000018B
_0802A9C8:
	movs r1, #2
	movs r2, #0
	movs r3, #0x10
	b _0802AA16
_0802A9D0:
	movs r1, #2
	movs r2, #0
	movs r3, #0x11
	b _0802AA16
_0802A9D8:
	movs r1, #2
	movs r2, #0
	movs r3, #0x12
	b _0802AA16
_0802A9E0:
	movs r1, #2
	movs r2, #0
	movs r3, #0x13
	b _0802AA16
_0802A9E8:
	movs r1, #2
	movs r2, #0
	movs r3, #0x14
	b _0802AA16
_0802A9F0:
	movs r1, #2
	movs r2, #0
	movs r3, #0x15
	b _0802AA16
_0802A9F8:
	movs r1, #2
	movs r2, #0
	movs r3, #0x16
	b _0802AA16
_0802AA00:
	movs r1, #2
	movs r2, #0
	movs r3, #0x17
	b _0802AA16
_0802AA08:
	movs r1, #2
	movs r2, #0
	movs r3, #0x18
	b _0802AA16
_0802AA10:
	movs r1, #2
	movs r2, #0
	movs r3, #0x19
_0802AA16:
	adds r0, r7, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r3, [r0]
_0802AA24:
	adds r0, #0x16
	str r2, [r0]
_0802AA28:
	adds r1, r7, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	b _0802AB0A
_0802AA32:
	ldrh r0, [r6, #8]
	ldr r3, _0802AA48 @ =0x0000018B
	adds r2, r5, r3
	strb r0, [r2]
_0802AA3A:
	movs r4, #0x8c
	lsls r4, r4, #1
	adds r0, r7, r4
_0802AA40:
	movs r1, #1
	bl MsgQueue_EndWait
	b _0802AB0A
	.align 2, 0
_0802AA48: .4byte 0x0000018B
_0802AA4C:
	movs r0, #8
	ldrsh r1, [r6, r0]
	cmp r1, #0
	bne _0802AAB8
	ldr r2, _0802AA88 @ =0x00000878
	adds r0, r5, r2
	strh r1, [r0]
	ldr r3, _0802AA8C @ =0x0000087C
	adds r1, r5, r3
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_08027ed0
	ldr r4, _0802AA90 @ =0x0000087A
	adds r1, r5, r4
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_08027ed0
	adds r1, r0, #0
	cmp r1, #0
	bne _0802AA94
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0x84
	lsls r2, r2, #3
	adds r0, r5, r2
	b _0802AAA2
	.align 2, 0
_0802AA88: .4byte 0x00000878
_0802AA8C: .4byte 0x0000087C
_0802AA90: .4byte 0x0000087A
_0802AA94:
	ldr r0, _0802AAB4 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r1, r5, r3
_0802AAA2:
	str r0, [r1]
	adds r0, r1, #0
	movs r4, #0xe7
	lsls r4, r4, #2
	adds r1, r5, r4
	ldr r0, [r0]
	str r0, [r1]
	b _0802AAFE
	.align 2, 0
_0802AAB4: .4byte 0x03003584
_0802AAB8:
	movs r0, #5
	movs r2, #0xce
	ldr r3, _0802AADC @ =0x0000087C
	adds r1, r5, r3
	movs r3, #0
	strb r0, [r1]
	ldr r4, _0802AAE0 @ =0x0000087A
	adds r0, r5, r4
	strh r2, [r0]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	bne _0802AAE8
	ldr r0, _0802AAE4 @ =0x00000878
	adds r1, r5, r0
	movs r0, #0x1f
	strh r0, [r1]
	b _0802AAFE
	.align 2, 0
_0802AADC: .4byte 0x0000087C
_0802AAE0: .4byte 0x0000087A
_0802AAE4: .4byte 0x00000878
_0802AAE8:
	cmp r0, #0
	bne _0802AAF8
	ldr r1, _0802AAF4 @ =0x00000878
	adds r0, r5, r1
	b _0802AAFC
	.align 2, 0
_0802AAF4: .4byte 0x00000878
_0802AAF8:
	ldr r2, _0802AB34 @ =0x00000878
	adds r0, r5, r2
_0802AAFC:
	strh r3, [r0]
_0802AAFE:
	movs r3, #0x8c
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #1
	bl MsgQueue_EndWait
_0802AB0A:
	movs r4, #1
	add sl, r4
	ldr r0, _0802AB38 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	ldr r0, [sp]
	adds r0, #6
_0802AB18:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp sl, r0
	bge _0802AB24
	b _0802A60C
_0802AB24:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802AB34: .4byte 0x00000878
_0802AB38: .4byte 0x03002B4C
