	push {r4, lr}
	bl Entity8AF6_FindEntry
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5AFA
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5AC8
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0xb4
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0xb6
	strh r0, [r1]
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0xb8
	strh r0, [r1]
_080A5AC8:
	movs r0, #0x66
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5ADC
	bl VM_GetValue
	adds r1, r4, #0
	adds r1, #0xa2
	strh r0, [r1]
_080A5ADC:
	adds r2, r4, #0
	adds r2, #0xac
	adds r0, r4, #0
	adds r0, #0xa4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r4, #0
	adds r1, #0xa0
	movs r0, #0
	strh r0, [r1]
	subs r1, #6
	movs r0, #1
	strh r0, [r1]
_080A5AFA:
	pop {r4}
	pop {r0}
	bx r0
