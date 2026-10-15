	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	movs r0, #0x74
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4348
	bl VM_GetValue
_080A4348:
	strb r0, [r6, #0x1a]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A43FC
	bl VM_GetValue
	adds r4, r6, #0
	adds r4, #0x64
	strh r0, [r4]
	bl VM_GetValue
	adds r5, r6, #0
	adds r5, #0x66
	strh r0, [r5]
	bl VM_GetValue
	adds r1, r6, #0
	adds r1, #0x68
	strh r0, [r1]
	adds r7, r4, #0
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A439A
	cmp r1, #0
	blt _080A439A
	ldr r0, _080A43A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A439A
	ldr r0, _080A43A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A43A8
_080A439A:
	movs r4, #0
	b _080A43B6
	.align 2, 0
_080A43A0: .4byte 0x030046A8
_080A43A4: .4byte 0x030046AC
_080A43A8:
	ldr r0, _080A43C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A43B6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080A43CC
	adds r0, #4
	b _080A43D8
	.align 2, 0
_080A43C8: .4byte 0x030046A4
_080A43CC:
	ldr r0, _080A43EC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A43D8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A43F0
	cmp r2, #2
	beq _080A43F4
	b _080A43F8
	.align 2, 0
_080A43EC: .4byte 0x030046A4
_080A43F0:
	ldrb r0, [r7, #4]
	b _080A43F6
_080A43F4:
	ldrb r0, [r7]
_080A43F6:
	subs r1, r1, r0
_080A43F8:
	strh r1, [r5]
	b _080A440A
_080A43FC:
	adds r0, r6, #0
	adds r0, #0x64
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_080A440A:
	movs r0, #0x52
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A4422
	bl VM_GetValue
	adds r1, r6, #0
	adds r1, #0xc0
	str r0, [r1]
	b _080A4428
_080A4422:
	adds r0, r6, #0
	adds r0, #0xc0
	str r1, [r0]
_080A4428:
	movs r0, #0x41
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4474
	movs r0, #0xb4
	adds r0, r0, r6
	mov r8, r0
	adds r7, r6, #0
	adds r7, #0x48
	movs r1, #0x1c
	adds r1, r1, r6
	mov sl, r1
	adds r2, r6, #0
	adds r2, #0x23
	str r2, [sp, #0xc]
	movs r0, #0x98
	adds r0, r0, r6
	mov sb, r0
	adds r1, r6, #0
	adds r1, #0x6c
	str r1, [sp]
	adds r2, #0x50
	str r2, [sp, #4]
	adds r0, r6, #0
	adds r0, #0x88
	str r0, [sp, #8]
	adds r4, r6, #0
	adds r4, #0xbc
	movs r5, #1
_080A4464:
	bl VM_GetValue
	strh r0, [r4]
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _080A4464
	b _080A44AE
_080A4474:
	movs r1, #0xb4
	adds r1, r1, r6
	mov r8, r1
	adds r7, r6, #0
	adds r7, #0x48
	movs r2, #0x1c
	adds r2, r2, r6
	mov sl, r2
	adds r0, r6, #0
	adds r0, #0x23
	str r0, [sp, #0xc]
	movs r1, #0x98
	adds r1, r1, r6
	mov sb, r1
	adds r2, r6, #0
	adds r2, #0x6c
	str r2, [sp]
	adds r0, #0x50
	str r0, [sp, #4]
	adds r1, r6, #0
	adds r1, #0x88
	str r1, [sp, #8]
	adds r1, #0x34
	movs r2, #0
	adds r0, #0x4b
_080A44A6:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _080A44A6
_080A44AE:
	ldrb r0, [r6, #0x1a]
	cmp r0, #0
	bne _080A44BE
	movs r0, #0x8e
	lsls r0, r0, #1
	mov r2, r8
	strh r0, [r2]
	b _080A44C4
_080A44BE:
	ldr r0, _080A4548 @ =0x0000011D
	mov r1, r8
	strh r0, [r1]
_080A44C4:
	ldr r5, _080A454C @ =0x0000A152
	adds r0, r7, #0
	adds r1, r5, #0
	bl Video_GetAuxSprite
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0
	bl AuxSprite_Add
	mov r2, r8
	ldrh r1, [r2]
	adds r0, r7, #0
	bl Video_SetAuxSpritePltt
	ldr r0, [r6, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r6, #0x1c]
	movs r4, #3
	ldr r0, [sp, #0xc]
	strb r4, [r0]
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	str r0, [r6, #0x38]
	str r1, [r6, #0x3c]
	mov r0, sb
	adds r1, r5, #0
	bl Video_GetAuxSprite
	ldr r0, [sp]
	mov r1, sb
	movs r2, #0
	bl AuxSprite_Add
	mov r2, r8
	ldrh r1, [r2]
	mov r0, sb
	bl Video_SetAuxSpritePltt
	ldr r0, [r6, #0x6c]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r6, #0x6c]
	ldr r0, [sp, #4]
	strb r4, [r0]
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	ldr r2, [sp, #8]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _080A4550 @ =Entity4759_UpdateIdle
	adds r0, r6, #0
	bl Entity4759_SetUpdateCallback
	movs r0, #0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A4548: .4byte 0x0000011D
_080A454C: .4byte 0x0000A152
_080A4550: .4byte Entity4759_UpdateIdle
