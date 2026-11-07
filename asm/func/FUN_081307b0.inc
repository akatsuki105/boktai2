	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	str r4, [sp, #8]
	ldr r2, _08130898 @ =0x0203B400
	mov sl, r2
	ldr r7, _0813089C @ =0x030046B8
	ldr r0, [r7]
	adds r0, #1
	ldr r6, _081308A0 @ =0x000003FF
	ands r0, r6
	lsls r1, r0, #1
	add r1, sl
	ldrh r1, [r1]
	ands r1, r6
	movs r2, #0x80
	lsls r2, r2, #1
	adds r2, r2, r1
	mov sb, r2
	adds r0, #1
	ands r0, r6
	str r0, [r7]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	subs r0, #0x3f
	ldrb r1, [r4, #5]
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r2, _081308A4 @ =0x00000484
	adds r0, r4, r2
	ldr r0, [r0]
	movs r1, #0x1e
	bl Mod
	cmp r0, #0
	beq _08130814
	b _081309C4
_08130814:
	ldr r0, _081308A8 @ =0x0000065C
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _08130822
	b _081309D0
_08130822:
	ldr r2, _081308AC @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r0, r0, #0xe
	ldrh r1, [r4, #8]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r3, _081308B0 @ =0xFFFF0000
	ldrh r1, [r4, #0xa]
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r0, r0, #0xe
	ldrh r2, [r4, #0xc]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
	ldr r1, _081308B4 @ =0x000004A4
	adds r0, r4, r1
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #8
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081308DC
	movs r1, #0x10
	movs r0, #0xcc
	lsls r0, r0, #3
	add r0, r8
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081308B8
	movs r0, #1
	b _081308BA
	.align 2, 0
_08130898: .4byte 0x0203B400
_0813089C: .4byte 0x030046B8
_081308A0: .4byte 0x000003FF
_081308A4: .4byte 0x00000484
_081308A8: .4byte 0x0000065C
_081308AC: .4byte gSineTable
_081308B0: .4byte 0xFFFF0000
_081308B4: .4byte 0x000004A4
_081308B8:
	movs r0, #0
_081308BA:
	cmp r0, #0
	bne _081308C6
	ldr r2, _081308D4 @ =0x00000482
	adds r1, r4, r2
	movs r0, #1
	strh r0, [r1]
_081308C6:
	adds r0, r4, #0
	bl Enemy_StepTowardPathNode
	ldr r1, _081308D8 @ =0x0000065C
	add r1, r8
	movs r0, #0
	b _081309D8
	.align 2, 0
_081308D4: .4byte 0x00000482
_081308D8: .4byte 0x0000065C
_081308DC:
	movs r0, #0x83
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r7]
	adds r0, #1
	ands r0, r6
	str r0, [r7]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0813090C
	ldr r2, _08130908 @ =0x00000482
	adds r1, r4, r2
	movs r0, #4
	b _08130912
	.align 2, 0
_08130908: .4byte 0x00000482
_0813090C:
	ldr r0, _0813093C @ =0x00000482
	adds r1, r4, r0
	movs r0, #1
_08130912:
	strh r0, [r1]
	ldr r1, _08130940 @ =0x000004A4
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r7, [sp, #8]
	adds r7, #8
	movs r2, #0x83
	lsls r2, r2, #2
	adds r5, r4, r2
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _08130944
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	b _0813096A
	.align 2, 0
_0813093C: .4byte 0x00000482
_08130940: .4byte 0x000004A4
_08130944:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08130964
	cmp r0, #2
	beq _08130960
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08130960:
	movs r0, #1
	b _08130974
_08130964:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
_0813096A:
	ldr r1, _0813099C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08130974:
	adds r5, r0, #0
	cmp r5, #0
	bne _08130986
	adds r0, r4, #0
	bl Enemy_StepTowardPathNode
	ldr r0, _081309A0 @ =0x0000065C
	add r0, r8
	strh r5, [r0]
_08130986:
	movs r1, #8
	movs r0, #0xcc
	lsls r0, r0, #3
	add r0, r8
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081309A4
	movs r0, #1
	b _081309A6
	.align 2, 0
_0813099C: .4byte 0xFFFFFDFF
_081309A0: .4byte 0x0000065C
_081309A4:
	movs r0, #0
_081309A6:
	cmp r0, #0
	beq _081309B8
	movs r1, #0x3c
	ldr r0, _081309B4 @ =0x0000065C
	add r0, r8
	strh r1, [r0]
	b _081309DA
	.align 2, 0
_081309B4: .4byte 0x0000065C
_081309B8:
	ldr r1, _081309C0 @ =0x0000065C
	add r1, r8
	movs r0, #0x78
	b _081309D8
	.align 2, 0
_081309C0: .4byte 0x0000065C
_081309C4:
	ldr r0, _081309EC @ =0x0000065C
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _081309DA
_081309D0:
	ldr r1, _081309EC @ =0x0000065C
	add r1, r8
	ldrh r0, [r1]
	subs r0, #1
_081309D8:
	strh r0, [r1]
_081309DA:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081309EC: .4byte 0x0000065C
