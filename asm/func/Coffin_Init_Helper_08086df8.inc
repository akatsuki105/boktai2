	push {r4, lr}
	adds r4, r0, #0
	strh r1, [r4, #0x18]
	bl Coffin_TakeKind
	ldr r3, _08086E48 @ =0x030046A0
	ldr r1, [r3]
	ldr r2, _08086E4C @ =0x00000252
	adds r1, r1, r2
	strh r0, [r1]
	ldr r0, [r3]
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r4, #0x1a]
	movs r0, #0x63
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08086E22
	bl VM_GetValue
_08086E22:
	strh r0, [r4, #0x1c]
	ldr r1, _08086E50 @ =0x085ABFE8
	ldrb r0, [r4, #0x1a]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x1e]
	movs r0, #0x61
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08086E54
	bl VM_GetValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl Coffin_SetState
	b _08086E5C
	.align 2, 0
_08086E48: .4byte 0x030046A0
_08086E4C: .4byte 0x00000252
_08086E50: .4byte 0x085ABFE8
_08086E54:
	adds r0, r4, #0
	movs r1, #0
	bl Coffin_SetState
_08086E5C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
