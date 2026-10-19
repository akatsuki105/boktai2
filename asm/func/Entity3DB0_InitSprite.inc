	push {r4, r5, r6, lr}
	adds r6, r1, #0
	adds r5, r0, #0
	adds r5, #0x18
	adds r4, r0, #0
	adds r4, #0x44
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1B6C
	bl VM_GetValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl Video_GetAuxSprite
	b _080A1B74
_080A1B6C:
	ldr r1, _080A1BB8 @ =0x00009D41
	adds r0, r4, #0
	bl Video_GetAuxSprite
_080A1B74:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1B8C
	bl VM_GetValue
_080A1B8C:
	strh r0, [r5, #0x10]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1BB0
	bl VM_GetValue
	cmp r0, #0
	beq _080A1BB0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_080A1BB0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A1BB8: .4byte 0x00009D41
