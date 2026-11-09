	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x24
	adds r5, r0, #0
	mov sb, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r3, _0810AA50 @ =0x0000046D
	adds r1, r5, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _0810AA54
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0810AA56
	.align 2, 0
_0810AA50: .4byte 0x0000046D
_0810AA54:
	movs r0, #0
_0810AA56:
	cmp r0, #0
	bne _0810AA5C
	b _0810ABC2
_0810AA5C:
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	ldrb r0, [r5, #5]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _0810AA76
	asrs r0, r1, #6
	b _0810AA7C
_0810AA76:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0810AA7C:
	lsls r0, r0, #0x1e
	lsrs r6, r0, #0x18
	add r3, sp, #0xc
	adds r4, r5, #0
	adds r4, #8
	ldr r0, _0810AAC0 @ =0x00000764
	adds r2, r2, r0
	ldrh r0, [r2]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	adds r0, r3, #0
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl ArcTan2_8
	mov r8, r0
	subs r1, r0, r6
	cmp r1, #0x80
	ble _0810AAC8
	ldr r3, _0810AAC4 @ =0xFFFFFF00
	adds r1, r1, r3
	b _0810AAD6
	.align 2, 0
_0810AAC0: .4byte 0x00000764
_0810AAC4: .4byte 0xFFFFFF00
_0810AAC8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0810AAD6
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r1, r4
_0810AAD6:
	adds r7, r1, #0
	add r3, sp, #0x14
	movs r4, #0xa
	ldr r2, _0810AAFC @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	mov ip, r3
	cmp r0, #0
	blt _0810AB00
	asrs r1, r0, #0xc
	b _0810AB06
	.align 2, 0
_0810AAFC: .4byte gSineTable
_0810AB00:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0810AB06:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0810AB1E
	asrs r0, r0, #0xc
	b _0810AB24
_0810AB1E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0810AB24:
	strh r0, [r3, #4]
	add r3, sp, #0x1c
	ldrh r0, [r3]
	mov r4, ip
	ldrh r4, [r4]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0810AB70 @ =0xFFFF0000
	ldr r2, [sp, #0x1c]
	ands r2, r4
	orrs r2, r0
	asrs r1, r2, #0x10
	movs r0, #0x82
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _0810AB74 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r1, sp, #0x14
	ldrh r0, [r3, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r3, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r3, #4]
	adds r1, r3, #0
	cmp r7, #0xc
	ble _0810AB78
	adds r0, r6, #0
	adds r0, #0xc
	lsls r0, r0, #0x18
	b _0810AB8C
	.align 2, 0
_0810AB70: .4byte 0xFFFF0000
_0810AB74: .4byte 0x0000FFFF
_0810AB78:
	movs r0, #0xc
	rsbs r0, r0, #0
	cmp r7, r0
	bge _0810AB88
	adds r0, r6, #0
	subs r0, #0xc
	lsls r0, r0, #0x18
	b _0810AB8C
_0810AB88:
	mov r2, r8
	lsls r0, r2, #0x18
_0810AB8C:
	lsrs r6, r0, #0x18
	movs r3, #0x8a
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r2, [r0]
	movs r4, #0x8c
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrh r3, [r0]
	adds r4, #0x14
	adds r0, r5, r4
	ldr r0, [r0]
	str r0, [sp]
	subs r4, #0xc
	adds r0, r5, r4
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0x2a
	str r0, [sp, #8]
	adds r0, r1, #0
	adds r1, r6, #0
	bl Entity081f0298_Spawn
	movs r0, #0xea
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0810ABC2:
	adds r0, r5, #0
	movs r1, #0x14
	bl Enemy_PlayAnim
	mov r0, sb
	cmp r0, #0x18
	ble _0810ABFA
	ldr r4, _0810AC08 @ =Skeleton_StateShootEnd
	movs r3, #0x2d
	ldr r2, _0810AC0C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0810AC10 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_0810ABFA:
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0810AC08: .4byte Skeleton_StateShootEnd
_0810AC0C: .4byte 0x0000046D
_0810AC10: .4byte 0x0000046B
