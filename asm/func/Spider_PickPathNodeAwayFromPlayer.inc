	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r0, #0x9c
	adds r0, r0, r5
	mov r8, r0
	movs r1, #0
	mov sb, r1
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r2, [r0]
	movs r3, #8
	ldrsh r0, [r2, r3]
	movs r7, #8
	ldrsh r1, [r5, r7]
	subs r0, r0, r1
	movs r3, #0xc
	ldrsh r1, [r2, r3]
	movs r7, #0xc
	ldrsh r2, [r5, r7]
	subs r1, r1, r2
	bl ArcTan2_8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _08130FDC @ =gSineTable
	adds r1, r0, #0
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r2, r1, #2
	adds r2, r2, r1
	lsls r2, r2, #5
	lsrs r2, r2, #0x10
	ldr r7, _08130FE0 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r7
	orrs r1, r2
	str r1, [sp]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #4]
	mov r1, r8
	ldr r0, [r1, #4]
	bl Map_GetPathNodes
	adds r4, r0, #0
	movs r6, #0
	mov r2, r8
	ldr r0, [r2, #4]
	ldrb r0, [r0]
	cmp sb, r0
	bge _08130FF2
	mov ip, r7
	add r3, sp, #8
	mov sl, sp
_08130F80:
	ldrh r1, [r4]
	ldrh r0, [r5, #8]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #8]
	mov r7, ip
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #8]
	ldrh r1, [r4, #2]
	ldrh r0, [r5, #0xc]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r3, #4]
	ands r0, r7
	orrs r0, r1
	str r0, [r3, #4]
	mov r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r1, r0, r1
	mov r0, sl
	movs r7, #4
	ldrsh r2, [r0, r7]
	movs r7, #4
	ldrsh r0, [r3, r7]
	muls r0, r2, r0
	adds r1, r1, r0
	cmp r1, #0
	bge _08130FE4
	ldr r1, [r4]
	adds r0, r5, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r1, r0
	beq _08130FE6
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	b _08131000
	.align 2, 0
_08130FDC: .4byte gSineTable
_08130FE0: .4byte 0xFFFF0000
_08130FE4:
	adds r4, #8
_08130FE6:
	adds r6, #1
	mov r1, r8
	ldr r0, [r1, #4]
	ldrb r0, [r0]
	cmp r6, r0
	blt _08130F80
_08130FF2:
	movs r0, #0
	cmp r0, #0
	bne _08131000
	adds r0, r5, #0
	bl Spider_PickRandomPathNode
	b _0813100C
_08131000:
	movs r0, #0
	mov r3, sb
	mov r2, r8
	strb r3, [r2, #2]
	strb r0, [r2, #3]
	str r4, [r2, #8]
_0813100C:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
