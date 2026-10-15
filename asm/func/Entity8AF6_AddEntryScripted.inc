	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	ldr r0, _080A5C44 @ =0x03002C4C
	ldr r2, [r0]
	cmp r2, #0
	bne _080A5C18
	b _080A5D62
_080A5C18:
	ldrb r0, [r2, #0x19]
	ldrb r1, [r2, #0x18]
	cmp r0, r1
	blo _080A5C22
	b _080A5D62
_080A5C22:
	adds r1, r0, #0
	movs r0, #0xbc
	muls r0, r1, r0
	adds r0, #0x1c
	adds r5, r2, r0
	movs r0, #0x6e
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A5C48
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	b _080A5C4E
	.align 2, 0
_080A5C44: .4byte 0x03002C4C
_080A5C48:
	adds r0, r5, #0
	adds r0, #0x98
	strh r1, [r0]
_080A5C4E:
	movs r0, #0x64
	bl VM_SeekToNamedArg
	cmp r0, #0
	bne _080A5C5A
	b _080A5D62
_080A5C5A:
	bl VM_GetValue
	adds r1, r0, #0
	ldr r0, _080A5C9C @ =0x0000CB05
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl GetFile
	adds r1, r0, #0
	adds r2, r5, #0
	adds r2, #0x18
	ldm r0!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	adds r4, r5, #0
	adds r4, #0x18
	adds r0, r4, #0
	bl OpenMainSpriteFile
	movs r0, #0x69
	bl VM_SeekToNamedArg
	mov r8, r4
	cmp r0, #0
	beq _080A5CA0
	bl VM_GetValue
	adds r7, r0, #0
	b _080A5CA2
	.align 2, 0
_080A5C9C: .4byte 0x0000CB05
_080A5CA0:
	movs r7, #0
_080A5CA2:
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5CB2
	bl VM_GetValue
	b _080A5CB4
_080A5CB2:
	movs r0, #0
_080A5CB4:
	movs r6, #0
	mov sb, r6
	cmp r0, #1
	bne _080A5CC0
	movs r0, #0x10
	mov sb, r0
_080A5CC0:
	movs r0, #0x52
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5CD2
	bl VM_GetValue
	adds r6, r0, #0
	b _080A5CD4
_080A5CD2:
	movs r6, #2
_080A5CD4:
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _080A5D00
	bl VM_GetValue
	adds r4, r5, #0
	adds r4, #0xa4
	strh r0, [r4]
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xa6
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0xa8
	strh r0, [r1]
	b _080A5D12
_080A5D00:
	adds r1, r5, #0
	adds r1, #0xa4
	strh r2, [r1]
	adds r0, r5, #0
	adds r0, #0xa6
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r4, r1, #0
_080A5D12:
	adds r0, r5, #0
	adds r0, #0x38
	lsls r2, r7, #0x10
	lsrs r2, r2, #0x10
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	mov r1, r8
	mov r3, sb
	bl MainSprite_Add
	movs r0, #0x41
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080A5D4A
	bl VM_GetValue
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	b _080A5D50
_080A5D4A:
	adds r0, r5, #0
	adds r0, #0x9c
	strh r1, [r0]
_080A5D50:
	adds r1, r5, #0
	adds r1, #0x9e
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080A5D70 @ =0x03002C4C
	ldr r1, [r0]
	ldrb r0, [r1, #0x19]
	adds r0, #1
	strb r0, [r1, #0x19]
_080A5D62:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A5D70: .4byte 0x03002C4C
