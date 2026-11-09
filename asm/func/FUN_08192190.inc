	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r0, #8
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0819226C
	movs r0, #9
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	ldr r2, _081921C4 @ =0x00000553
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0x26
	bne _081921C8
	movs r3, #0xf4
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	lsls r1, r0, #1
	b _081921D0
	.align 2, 0
_081921C4: .4byte 0x00000553
_081921C8:
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
_081921D0:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, r1
	bhi _0819226C
	mov r5, sp
	adds r3, r4, #0
	adds r3, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r4, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #4
	ldrsh r1, [r5, r3]
	bl ArcTan2_8
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #6
	ldrb r1, [r4, #5]
	adds r1, #0x10
	ands r1, r3
	asrs r1, r1, #6
	cmp r0, r1
	bne _0819226C
	movs r0, #2
	ldrsh r1, [r5, r0]
	cmp r1, #0
	bge _08192234
	rsbs r1, r1, #0
_08192234:
	ldr r0, _08192260 @ =0x000001FF
	cmp r1, r0
	bgt _0819226C
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	adds r1, #0x30
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #0x80
	ands r0, r3
	asrs r0, r0, #6
	ldr r3, _08192264 @ =0x00000F45
	adds r1, r2, r3
	strb r0, [r1]
	ldr r0, _08192268 @ =0x00000F44
	adds r2, r2, r0
	movs r0, #0xe
	strb r0, [r2]
	movs r0, #1
	b _0819226E
	.align 2, 0
_08192260: .4byte 0x000001FF
_08192264: .4byte 0x00000F45
_08192268: .4byte 0x00000F44
_0819226C:
	movs r0, #0
_0819226E:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
