	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #8]
	mov sb, r1
	mov r8, r2
	adds r7, r3, #0
	ldr r0, [sp, #0x30]
	mov sl, r0
	ldr r0, _08004F18 @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	bne _08004F1C
	movs r0, #1
	rsbs r0, r0, #0
	b _08004F74
	.align 2, 0
_08004F18: .4byte 0x03000024
_08004F1C:
	ldr r5, [r0, #0x18]
	cmp r5, #0
	beq _08004F72
_08004F22:
	ldr r6, [r5, #0x20]
	ldrh r0, [r5]
	ldr r1, [sp, #8]
	cmp r0, r1
	bne _08004F6C
	movs r0, #1
	rsbs r0, r0, #0
	cmp r8, r0
	beq _08004F38
	mov r2, r8
	strb r2, [r5, #3]
_08004F38:
	cmp sb, r0
	beq _08004F40
	mov r1, sb
	strb r1, [r5, #4]
_08004F40:
	ldr r2, [sp, #0x2c]
	cmp r2, r0
	beq _08004F48
	strh r2, [r5, #8]
_08004F48:
	cmp sl, r0
	beq _08004F50
	mov r2, sl
	strb r2, [r5, #5]
_08004F50:
	cmp r7, r0
	beq _08004F56
	strh r7, [r5, #6]
_08004F56:
	adds r0, r5, #0
	adds r0, #0xc
	ldrh r1, [r5, #8]
	ldrb r2, [r5, #4]
	ldrb r3, [r5, #5]
	movs r4, #0xff
	str r4, [sp]
	ldrh r4, [r5, #6]
	str r4, [sp, #4]
	bl FUN_08234208
_08004F6C:
	adds r5, r6, #0
	cmp r5, #0
	bne _08004F22
_08004F72:
	movs r0, #0
_08004F74:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
