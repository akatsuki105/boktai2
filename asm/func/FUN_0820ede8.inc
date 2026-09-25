	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	bl FUN_0820d21c
	adds r4, r7, #0
	adds r4, #0x25
	ldrb r0, [r4]
	bl FUN_0820cbdc
	mov sl, r0
	ldrb r0, [r4]
	bl FUN_0820cbec
	mov r8, r0
	movs r6, #0
	cmp r6, r8
	bge _0820EE6C
	adds r5, r7, #0
	adds r5, #0x28
	movs r0, #5
	mov sb, r0
_0820EE1C:
	ldr r0, [r5]
	ldr r2, _0820EE50 @ =0x00001110
	adds r1, r7, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r5]
	movs r1, #2
	str r1, [sp]
	movs r1, #6
	mov r2, sb
	movs r3, #0x14
	bl TextPanel_SetRect
	mov r0, sl
	adds r4, r0, r6
	adds r0, r4, #0
	bl FUN_0820d00c
	cmp r0, #0
	beq _0820EE54
	ldr r0, [r5]
	adds r1, r4, #0
	bl TextPanel_SetMessage
	b _0820EE5C
	.align 2, 0
_0820EE50: .4byte 0x00001110
_0820EE54:
	ldr r0, [r5]
	movs r1, #0x39
	bl TextPanel_SetMessage
_0820EE5C:
	ldm r5!, {r0}
	bl TextPanel_Start
	movs r2, #2
	add sb, r2
	adds r6, #1
	cmp r6, r8
	blt _0820EE1C
_0820EE6C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
