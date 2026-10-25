	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, _080C5154 @ =0x000025BD
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080C5158 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _080C515C @ =0x00002AA0
	adds r0, r0, r1
	ldr r2, _080C5160 @ =0x0000259C
	adds r1, r6, r2
	ldr r2, _080C5164 @ =0x04000008
	bl CpuSet
	movs r5, #0
_080C5146:
	cmp r5, #4
	bhi _080C51A2
	lsls r0, r5, #2
	ldr r1, _080C5168 @ =_080C516C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080C5154: .4byte 0x000025BD
_080C5158: .4byte 0x03003584
_080C515C: .4byte 0x00002AA0
_080C5160: .4byte 0x0000259C
_080C5164: .4byte 0x04000008
_080C5168: .4byte _080C516C
_080C516C: @ jump table
	.4byte _080C5180 @ case 0
	.4byte _080C5186 @ case 1
	.4byte _080C5190 @ case 2
	.4byte _080C519A @ case 3
	.4byte _080C51A2 @ case 4
_080C5180:
	movs r7, #1
	movs r2, #0
	b _080C518A
_080C5186:
	movs r7, #1
	movs r2, #0x18
_080C518A:
	movs r3, #0
	movs r1, #1
	b _080C51AA
_080C5190:
	movs r7, #0
	movs r2, #0
	movs r3, #0
	movs r1, #2
	b _080C51AA
_080C519A:
	movs r7, #0
	movs r2, #0
	movs r3, #0
	b _080C51A8
_080C51A2:
	movs r7, #0
	movs r2, #0
	movs r3, #1
_080C51A8:
	movs r1, #3
_080C51AA:
	movs r0, #0x98
	adds r4, r5, #0
	muls r4, r0, r4
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r0, r0, r4
	mov ip, r0
	add ip, r6
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	mov r0, ip
	adds r1, r7, #0
	bl FUN_080c5058
	cmp r7, #0
	bne _080C51D2
	movs r1, #0xc6
	lsls r1, r1, #2
	b _080C51D6
_080C51D2:
	movs r1, #0xdd
	lsls r1, r1, #2
_080C51D6:
	adds r0, r6, r1
	adds r0, r0, r4
	ldr r2, _080C5224 @ =0x0000259C
	adds r1, r6, r2
	str r1, [r0]
	adds r5, #1
	cmp r5, #4
	ble _080C5146
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r5, #2
	str r5, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r1, #1
	movs r2, #0x2a
	movs r3, #0
	bl FUN_080c5058
	movs r2, #0xbf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r5, [sp]
	str r4, [sp, #4]
	movs r1, #1
	movs r2, #0x2e
	movs r3, #0
	bl FUN_080c5058
	movs r5, #0
_080C5214:
	cmp r5, #1
	beq _080C5232
	cmp r5, #1
	bgt _080C5228
	cmp r5, #0
	beq _080C522E
	b _080C523A
	.align 2, 0
_080C5224: .4byte 0x0000259C
_080C5228:
	cmp r5, #2
	beq _080C5236
	b _080C523A
_080C522E:
	movs r2, #0x21
	b _080C523C
_080C5232:
	movs r2, #0x1e
	b _080C523C
_080C5236:
	movs r2, #0x1b
	b _080C523C
_080C523A:
	movs r2, #0
_080C523C:
	movs r0, #0x98
	adds r4, r5, #0
	muls r4, r0, r4
	movs r1, #0xe5
	lsls r1, r1, #3
	adds r0, r4, r1
	adds r0, r6, r0
	movs r1, #2
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	movs r3, #0
	bl FUN_080c5058
	ldr r2, _080C52D0 @ =0x0000079C
	adds r0, r6, r2
	adds r0, r0, r4
	ldr r2, _080C52D4 @ =0x0000259C
	adds r1, r6, r2
	str r1, [r0]
	adds r5, #1
	cmp r5, #2
	ble _080C5214
	movs r0, #0xbe
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #0xa0
	lsls r0, r0, #3
	strh r0, [r2]
	ldr r0, _080C52D8 @ =0x000002FA
	adds r1, r6, r0
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0xbf
	lsls r0, r0, #2
	adds r1, r6, r0
	subs r0, #0xfc
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r3, r6, r1
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r2, _080C52DC @ =0x000002EA
	adds r1, r6, r2
	subs r2, #0x6a
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r6, r0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C52D0: .4byte 0x0000079C
_080C52D4: .4byte 0x0000259C
_080C52D8: .4byte 0x000002FA
_080C52DC: .4byte 0x000002EA
