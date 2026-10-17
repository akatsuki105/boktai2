	push {r4, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4FCC
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4FCC
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0x2f
	strb r0, [r1]
_080A4FCC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
