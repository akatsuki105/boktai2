	push {r4, r5, lr}
	ldr r0, _080027E0 @ =0x03002B30
	ldr r4, [r0]
	cmp r4, #0
	beq _080027FA
	movs r0, #0x72
	movs r1, #0
	bl VM_GetNamedArgValue
	strh r0, [r4, #0x24]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080027FA
	movs r5, #0
	adds r4, #0x26
	b _080027EE
	.align 2, 0
_080027E0: .4byte 0x03002B30
_080027E4:
	bl VM_GetValue
	strh r0, [r4]
	adds r4, #2
	adds r5, #1
_080027EE:
	bl VM_GetPC
	cmp r0, #0
	beq _080027FA
	cmp r5, #6
	ble _080027E4
_080027FA:
	pop {r4, r5}
	pop {r0}
	bx r0
