	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _0801FFA0 @ =0x000085E6
	bl FUN_08230e70
	adds r6, r0, #0
	cmp r6, #0
	beq _0801FF98
	movs r7, #0
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _0801FFA4
_0801FF98:
	movs r0, #1
	rsbs r0, r0, #0
	b _0801FFFC
	.align 2, 0
_0801FFA0: .4byte 0x000085E6
_0801FFA4:
	bl Script_GetValue
	mov sb, r0
	movs r5, #0
	ldrh r0, [r6, #0x1a]
	cmp r7, r0
	bge _0801FFFA
	ldr r2, _08020008 @ =0x0000042C
	adds r2, r2, r6
	mov r8, r2
_0801FFB8:
	movs r0, #0x8c
	adds r1, r5, #0
	muls r1, r0, r1
	mov r2, r8
	ldr r0, [r2]
	adds r4, r0, r1
	ldrh r0, [r4, #0x34]
	cmp r0, sb
	bne _0801FFF2
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0801FFDA
	bl Script_GetValue
	str r0, [r4, #0x64]
_0801FFDA:
	adds r1, r4, #0
	adds r1, #0x37
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801FFE8
	cmp r0, #2
	bne _0801FFF0
_0801FFE8:
	movs r0, #3
	strb r0, [r1]
	ldr r0, _0802000C @ =FUN_08020b24
	str r0, [r4, #0x30]
_0801FFF0:
	movs r7, #1
_0801FFF2:
	adds r5, #1
	ldrh r0, [r6, #0x1a]
	cmp r5, r0
	blt _0801FFB8
_0801FFFA:
	adds r0, r7, #0
_0801FFFC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08020008: .4byte 0x0000042C
_0802000C: .4byte FUN_08020b24
