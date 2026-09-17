	push {r4, lr}
	adds r4, r0, #0
	ldr r3, [r1, #0x64]
	ldr r2, [r1, #0x68]
	ldrb r0, [r1]
	cmp r0, #0
	bne _08013968
	movs r0, #1
	rsbs r0, r0, #0
	b _0801397C
_08013968:
	cmp r3, #0
	beq _08013970
	str r2, [r3, #0x68]
	b _08013972
_08013970:
	str r2, [r4, #0x1c]
_08013972:
	cmp r2, #0
	beq _08013978
	str r3, [r2, #0x64]
_08013978:
	movs r0, #0
	strb r0, [r1]
_0801397C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
