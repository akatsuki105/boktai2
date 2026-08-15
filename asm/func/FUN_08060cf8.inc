	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	adds r5, r2, #0
	adds r1, #0x40
	ldrh r0, [r1]
	adds r6, r5, #0
	adds r6, #0x40
	movs r7, #0
	strh r0, [r6]
	ldrh r0, [r1]
	cmp r0, #0xc8
	bls _08060D16
	movs r0, #0xc8
	strh r0, [r6]
_08060D16:
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r2, [r3, #0x38]
	ands r2, r0
	cmp r2, #0
	beq _08060D40
	ldr r0, _08060D3C @ =0x000003D2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r3, #0
	adds r1, r5, #0
	bl FUN_08060c98
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	b _08060E10
	.align 2, 0
_08060D3C: .4byte 0x000003D2
_08060D40:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08060D58
	ldrh r0, [r5, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r5, #6]
	strh r2, [r6]
	b _08060E12
_08060D58:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _08060DFC
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08060D8C
	adds r0, r3, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r1, r4, r2
	b _08060DDC
_08060D8C:
	movs r0, #0x24
	ldrsh r1, [r3, r0]
	movs r2, #0x24
	ldrsh r0, [r5, r2]
	subs r2, r1, r0
	movs r0, #0x28
	ldrsh r1, [r3, r0]
	movs r3, #0x28
	ldrsh r0, [r5, r3]
	subs r1, r1, r0
	cmp r2, #0
	bne _08060DBA
	cmp r1, #0
	bne _08060DBA
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	b _08060DDE
_08060DBA:
	adds r0, r2, #0
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	adds r0, #4
	ands r0, r1
	movs r3, #0xfa
	lsls r3, r3, #2
	adds r1, r4, r3
_08060DDC:
	strh r0, [r1]
_08060DDE:
	adds r3, r5, #0
	adds r3, #0x40
	ldrh r2, [r3]
	ldr r1, _08060DF8 @ =0x000003E6
	adds r0, r4, r1
	movs r1, #0
	strh r2, [r0]
	strh r1, [r3]
	ldrh r1, [r5, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r5, #6]
	b _08060E12
	.align 2, 0
_08060DF8: .4byte 0x000003E6
_08060DFC:
	ldr r2, _08060E18 @ =0x000003D2
	adds r0, r4, r2
	strb r7, [r0]
	adds r0, r3, #0
	adds r1, r5, #0
	bl FUN_08060c98
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r4, r3
_08060E10:
	strb r0, [r1]
_08060E12:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08060E18: .4byte 0x000003D2
