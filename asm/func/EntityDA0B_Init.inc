	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r0, _0801E13C @ =0x03000098
	str r4, [r0]
	ldr r0, _0801E140 @ =0x0000CB05
	mov r8, r0
	ldr r1, _0801E144 @ =0x0000414C
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _0801E09E
	b _0801E1A6
_0801E09E:
	adds r0, r4, #0
	adds r0, #0xd8
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r5, r6, r7}
	stm r2!, {r5, r6, r7}
	ldm r1!, {r5, r6, r7}
	stm r2!, {r5, r6, r7}
	ldm r1!, {r5, r6}
	stm r2!, {r5, r6}
	adds r1, r3, #0
	bl OpenMainSpriteFile
	ldr r1, _0801E148 @ =0x0000B343
	mov r0, r8
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0801E1A6
	adds r0, r4, #0
	adds r0, #0xf8
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r5, r6, r7}
	stm r2!, {r5, r6, r7}
	ldm r1!, {r5, r6, r7}
	stm r2!, {r5, r6, r7}
	ldm r1!, {r5, r7}
	stm r2!, {r5, r7}
	adds r1, r3, #0
	bl OpenMainSpriteFile
	ldr r1, _0801E14C @ =0x00005D04
	mov r0, r8
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0801E1A6
	movs r6, #0x8c
	lsls r6, r6, #1
	adds r0, r4, r6
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r5, r6, r7}
	stm r2!, {r5, r6, r7}
	ldm r1!, {r5, r6, r7}
	stm r2!, {r5, r6, r7}
	ldm r1!, {r5, r7}
	stm r2!, {r5, r7}
	adds r1, r3, #0
	bl OpenMainSpriteFile
	ldr r1, _0801E150 @ =0x0000B156
	movs r0, #0x6e
	bl VM_GetNamedArgValue
	ldr r6, _0801E154 @ =0x0000131C
	adds r1, r4, r6
	strh r0, [r1]
	ldr r7, _0801E158 @ =0x0000131E
	adds r1, r4, r7
	movs r0, #5
	strh r0, [r1]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0801E15C
	bl VM_GetValue
	strh r0, [r4, #0x18]
	bl VM_GetValue
	strh r0, [r4, #0x1a]
	bl VM_GetValue
	b _0801E160
	.align 2, 0
_0801E13C: .4byte 0x03000098
_0801E140: .4byte 0x0000CB05
_0801E144: .4byte 0x0000414C
_0801E148: .4byte 0x0000B343
_0801E14C: .4byte 0x00005D04
_0801E150: .4byte 0x0000B156
_0801E154: .4byte 0x0000131C
_0801E158: .4byte 0x0000131E
_0801E15C:
	strh r0, [r4, #0x18]
	strh r0, [r4, #0x1a]
_0801E160:
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, [r4, #0x18]
	ldr r2, [r4, #0x1c]
	str r1, [r4, #0x20]
	str r2, [r4, #0x24]
	bl FUN_0823b8ac
	movs r0, #0x63
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r4, #0
	adds r1, #0xb8
	strh r0, [r1]
	movs r0, #0x65
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r1, r4, #0
	adds r1, #0xba
	strh r0, [r1]
	movs r0, #0x77
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0801E1A6
	bl FUN_0823d340
	ldr r2, _0801E1AC @ =0x00001308
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	bne _0801E1B0
_0801E1A6:
	movs r0, #1
	rsbs r0, r0, #0
	b _0801E206
	.align 2, 0
_0801E1AC: .4byte 0x00001308
_0801E1B0:
	movs r0, #0x6b
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0801E1A6
	bl FUN_0823d340
	ldr r5, _0801E210 @ =0x0000130C
	adds r1, r4, r5
	str r0, [r1]
	cmp r0, #0
	beq _0801E1A6
	adds r0, r4, #0
	bl FUN_0801c260
	adds r0, r4, #0
	bl FUN_0801c4bc
	adds r0, r4, #0
	bl FUN_0801c204
	adds r0, r4, #0
	bl FUN_0801c2bc
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl TextBox_SetRect
	adds r0, r4, #0
	bl FUN_0801c910
	adds r0, r4, #0
	bl FUN_0801d084
	ldr r1, _0801E214 @ =FUN_0801c9e4
	adds r0, r4, #0
	bl EntityDA0B_SetFn
	bl FUN_08049f5c
	movs r0, #0
_0801E206:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801E210: .4byte 0x0000130C
_0801E214: .4byte FUN_0801c9e4
