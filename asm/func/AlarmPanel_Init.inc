	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	strh r1, [r6, #0x18]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1874
	bl VM_GetValue
	strh r0, [r6, #0x28]
	bl VM_GetValue
	strh r0, [r6, #0x2a]
	bl VM_GetValue
	b _080A1878
_080A1874:
	strh r0, [r6, #0x28]
	strh r0, [r6, #0x2a]
_080A1878:
	strh r0, [r6, #0x2c]
	adds r5, r6, #0
	adds r5, #0x64
	adds r4, r6, #0
	adds r4, #0x90
	ldr r1, _080A1900 @ =0x0000A680
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #0xa
	strh r0, [r5, #0x10]
	movs r0, #3
	strb r0, [r5, #7]
	adds r0, r4, #0
	movs r1, #0x46
	bl Video_SetAuxSpritePltt
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A18BE
	bl VM_GetValue
	cmp r0, #0
	beq _080A18BE
	ldr r0, [r6, #0x64]
	movs r1, #4
	orrs r0, r1
	str r0, [r6, #0x64]
_080A18BE:
	movs r0, #0
	strh r0, [r6, #0x1e]
	ldr r0, [r6, #0x28]
	ldr r1, [r6, #0x2c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r0, #0x68
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1904
	bl VM_GetValue
	strh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A1906
	adds r4, r6, #0
	adds r4, #0x20
	ldrh r1, [r6, #0x18]
	adds r2, r5, #0
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Mover_Init
	adds r0, r4, #0
	bl FUN_08002a48
	b _080A1906
	.align 2, 0
_080A1900: .4byte 0x0000A680
_080A1904:
	strh r0, [r6, #0x1c]
_080A1906:
	adds r5, r6, #0
	adds r5, #0xac
	adds r4, r6, #0
	adds r4, #0xd8
	ldr r1, _080A196C @ =0x0000A680
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #0xb
	strh r0, [r5, #0x10]
	movs r0, #1
	strb r0, [r5, #7]
	adds r0, r4, #0
	movs r1, #0x45
	bl Video_SetAuxSpritePltt
	ldr r0, [r5]
	ldr r1, _080A1970 @ =0x00000201
	orrs r0, r1
	str r0, [r5]
	ldr r0, [r6, #0x28]
	ldr r1, [r6, #0x2c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldrh r0, [r5, #0x1c]
	subs r0, #0x80
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x20]
	subs r0, #0x80
	strh r0, [r5, #0x20]
	movs r0, #0x52
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A195E
	bl VM_GetValue
	adds r2, r0, #0
_080A195E:
	adds r1, r6, #0
	adds r1, #0xf4
	str r2, [r1]
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A196C: .4byte 0x0000A680
_080A1970: .4byte 0x00000201
