	push {r4, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4F70
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4F70
	bl VM_GetValue
	strh r0, [r4, #0x38]
_080A4F70:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
