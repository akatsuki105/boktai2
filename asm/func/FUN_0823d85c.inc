	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r7, #0
	movs r4, #0
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0823D876
	bl Script_GetValue
	adds r7, r0, #0
_0823D876:
	movs r6, #0
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _0823D892
	bl VM_GetPC
	add r2, sp, #4
	mov r1, sp
	bl VM_Step
	ldr r4, [sp, #4]
	b _0823D8A4
_0823D892:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0823D8A4
	movs r6, #1
	bl Script_GetValue
	adds r4, r0, #0
_0823D8A4:
	adds r0, r4, #0
	movs r1, #0
	adds r2, r7, #0
	bl FUN_0823d7d8
	adds r4, r0, #0
	cmp r4, #0
	beq _0823D8E8
	str r5, [r4, #0x18]
	strh r6, [r4, #0x2e]
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _0823D8E8
	adds r0, r4, #0
	adds r0, #0x30
	str r0, [r4, #0x20]
	movs r5, #0
	b _0823D8DA
_0823D8CC:
	bl Script_GetValue
	ldr r2, [r4, #0x20]
	lsls r1, r5, #2
	adds r1, r1, r2
	str r0, [r1]
	adds r5, #1
_0823D8DA:
	cmp r5, #7
	bgt _0823D8E6
	bl VM_GetPC
	cmp r0, #0
	bne _0823D8CC
_0823D8E6:
	strh r5, [r4, #0x1c]
_0823D8E8:
	adds r0, r4, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

