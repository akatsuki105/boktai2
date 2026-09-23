	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _0801FEF8 @ =0x000085E6
	bl FUN_08230e70
	adds r6, r0, #0
	cmp r6, #0
	bne _0801FEFC
	movs r0, #1
	rsbs r0, r0, #0
	b _0801FF64
	.align 2, 0
_0801FEF8: .4byte 0x000085E6
_0801FEFC:
	movs r7, #0
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _0801FF0C
	movs r0, #0
	b _0801FF64
_0801FF0C:
	bl Script_GetValue
	mov sb, r0
	movs r5, #0
	ldrh r0, [r6, #0x1a]
	cmp r7, r0
	bge _0801FF62
	ldr r2, _0801FF70 @ =0x0000042C
	adds r2, r2, r6
	mov r8, r2
_0801FF20:
	movs r0, #0x8c
	adds r1, r5, #0
	muls r1, r0, r1
	mov r2, r8
	ldr r0, [r2]
	adds r4, r0, r1
	ldrh r0, [r4, #0x34]
	cmp r0, sb
	bne _0801FF5A
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0801FF42
	bl Script_GetValue
	str r0, [r4, #0x60]
_0801FF42:
	adds r1, r4, #0
	adds r1, #0x37
	ldrb r0, [r1]
	cmp r0, #1
	beq _0801FF50
	cmp r0, #3
	bne _0801FF58
_0801FF50:
	movs r0, #2
	strb r0, [r1]
	ldr r0, _0801FF74 @ =FUN_08020af8
	str r0, [r4, #0x30]
_0801FF58:
	movs r7, #1
_0801FF5A:
	adds r5, #1
	ldrh r0, [r6, #0x1a]
	cmp r5, r0
	blt _0801FF20
_0801FF62:
	adds r0, r7, #0
_0801FF64:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801FF70: .4byte 0x0000042C
_0801FF74: .4byte FUN_08020af8
