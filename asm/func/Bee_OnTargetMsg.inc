	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08167A52
	b _08167C04
_08167A52:
	movs r1, #0x80
	lsls r1, r1, #7
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08167A66
	b _08167C04
_08167A66:
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r4, [r0]
	ldrh r1, [r5, #2]
	movs r2, #0xd8
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r7, #0
	strh r1, [r0]
	ldrh r0, [r0]
	bl Mover_FindByID_Proxy
	ldr r1, _08167B10 @ =0x000006C4
	adds r3, r4, r1
	str r0, [r3]
	ldrh r1, [r5, #4]
	ldr r2, _08167B14 @ =0x000006C2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r5, _08167B18 @ =0x000006AC
	adds r0, r4, r5
	strb r7, [r0]
	add r2, sp, #4
	adds r0, r6, #0
	adds r0, #8
	str r0, [sp, #0x14]
	ldr r0, [r3]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldr r5, [sp, #0x14]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r3, r6, r5
	strb r0, [r3]
	ldr r2, _08167B1C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08167B20 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08167B24 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	ldrb r3, [r3]
	adds r3, r0, r3
	movs r1, #0xff
	add r7, sp, #0xc
	ands r3, r1
	ldr r2, _08167B28 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #9
	ldr r5, [sp, #0x14]
	adds r2, r7, #0
	cmp r0, #0
	blt _08167B2C
	asrs r1, r0, #0xc
	b _08167B32
	.align 2, 0
_08167B10: .4byte 0x000006C4
_08167B14: .4byte 0x000006C2
_08167B18: .4byte 0x000006AC
_08167B1C: .4byte 0x030046B8
_08167B20: .4byte 0x000003FF
_08167B24: .4byte 0x0203B400
_08167B28: .4byte gSineTable
_08167B2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08167B32:
	movs r0, #0
	strh r1, [r7]
	strh r0, [r7, #2]
	ldr r1, _08167B50 @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _08167B54
	asrs r0, r0, #0xc
	b _08167B5A
	.align 2, 0
_08167B50: .4byte gSineTable
_08167B54:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08167B5A:
	movs r1, #0
	mov sb, r1
	movs r3, #0
	mov r8, r3
	strh r0, [r7, #4]
	ldr r0, _08167C14 @ =0x000006BE
	adds r1, r4, r0
	movs r0, #0xa0
	lsls r0, r0, #3
	strh r0, [r1]
	add r1, sp, #0xc
	ldrh r0, [r6, #8]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r6, #0
	adds r1, r2, #0
	str r2, [sp, #0x18]
	bl Bee_BuildCurvePoints
	adds r0, r6, #0
	adds r1, r5, #0
	ldr r2, [sp, #0x18]
	bl FUN_0816869c
	ldr r2, _08167C18 @ =0x00000704
	adds r1, r4, r2
	mov r3, r8
	str r3, [sp]
	mov r0, sp
	ldr r2, _08167C1C @ =0x05000002
	bl CpuSet
	movs r1, #2
	movs r2, #6
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	ldr r1, _08167C20 @ =0x00000469
	adds r0, r6, r1
	mov r3, sb
	strb r3, [r0]
	adds r5, #2
	adds r0, r6, r5
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r6, r1
	mov r2, r8
	str r2, [r0]
	ldr r3, _08167C24 @ =0x0000046C
	adds r0, r6, r3
	movs r1, #1
	strb r1, [r0]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r6, r5
	ldr r2, [r0]
	adds r3, #1
	adds r0, r6, r3
	strb r1, [r0]
	ldr r5, _08167C28 @ =0x0000046B
	adds r0, r6, r5
	mov r3, sb
	strb r3, [r0]
	adds r5, #0xe8
	adds r0, r6, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	mov r3, r8
	strh r3, [r0]
_08167C04:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08167C14: .4byte 0x000006BE
_08167C18: .4byte 0x00000704
_08167C1C: .4byte 0x05000002
_08167C20: .4byte 0x00000469
_08167C24: .4byte 0x0000046C
_08167C28: .4byte 0x0000046B
