	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _08181AA8 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08181AAC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08181AAE
	.align 2, 0
_08181AA8: .4byte 0x0000046C
_08181AAC:
	movs r0, #0
_08181AAE:
	cmp r0, #0
	beq _08181AFA
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _08181B94 @ =FUN_0817fac8
	movs r2, #0x22
	ldr r0, _08181B98 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08181B9C @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	ldr r3, _08181BA0 @ =0x00000553
	adds r0, r6, r3
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	ldr r3, _08181BA4 @ =0x00000888
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r2, _08181BA8 @ =0x0000087C
	adds r0, r7, r2
	strh r1, [r0]
_08181AFA:
	ldr r3, _08181B9C @ =0x0000046B
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08181BEC
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _08181BAC @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r5, #0
	strh r1, [r2]
	ldr r1, _08181BB0 @ =FUN_0817fbe0
	mov ip, r1
	movs r1, #0x2d
	ldr r2, _08181B98 @ =0x0000046D
	adds r0, r6, r2
	movs r4, #1
	strb r4, [r0]
	subs r2, #2
	adds r0, r6, r2
	strb r3, [r0]
	adds r2, #0xe8
	adds r0, r6, r2
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	mov r2, ip
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
	movs r1, #2
	movs r2, #3
	mov ip, r2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _08181BB4 @ =0x00000469
	adds r0, r6, r3
	strb r1, [r0]
	ldr r1, _08181BB8 @ =0x0000046A
	adds r0, r6, r1
	mov r2, ip
	strb r2, [r0]
	adds r3, #0x1b
	adds r0, r6, r3
	str r5, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _08181BBC @ =0x0000089F
	adds r0, r7, r2
	movs r2, #0x50
	strb r2, [r0]
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r3, _08181BC0 @ =0x00000546
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r1, r0
	bgt _08181BC4
	movs r0, #0x28
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	b _08181BCC
	.align 2, 0
_08181B94: .4byte FUN_0817fac8
_08181B98: .4byte 0x0000046D
_08181B9C: .4byte 0x0000046B
_08181BA0: .4byte 0x00000553
_08181BA4: .4byte 0x00000888
_08181BA8: .4byte 0x0000087C
_08181BAC: .4byte 0xFFFFFEFF
_08181BB0: .4byte FUN_0817fbe0
_08181BB4: .4byte 0x00000469
_08181BB8: .4byte 0x0000046A
_08181BBC: .4byte 0x0000089F
_08181BC0: .4byte 0x00000546
_08181BC4:
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r2, [r0]
_08181BCC:
	movs r0, #0xc9
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	ldrh r1, [r2]
	ldr r2, _08181BE8 @ =0x000008AA
	adds r0, r7, r2
	strh r1, [r0]
	b _08181BF6
	.align 2, 0
_08181BE8: .4byte 0x000008AA
_08181BEC:
	ldr r3, _08181BFC @ =0x00000484
	adds r1, r6, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08181BF6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08181BFC: .4byte 0x00000484
