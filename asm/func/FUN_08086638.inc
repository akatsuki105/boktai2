	push {r4, r5, r6, lr}
	ldr r0, _080866C8 @ =0x03002C00
	ldr r5, [r0]
	cmp r5, #0
	beq _080866DC
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0808666E
	bl VM_GetValue
	movs r2, #0xea
	lsls r2, r2, #2
	adds r1, r5, r2
	strh r0, [r1]
	bl VM_GetValue
	ldr r2, _080866CC @ =0x000003AA
	adds r1, r5, r2
	strh r0, [r1]
	bl VM_GetValue
	movs r2, #0xeb
	lsls r2, r2, #2
	adds r1, r5, r2
	strh r0, [r1]
_0808666E:
	movs r0, #0x52
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08086684
	bl VM_GetValue
	movs r2, #0xec
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
_08086684:
	ldr r1, _080866D0 @ =0x000001F5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _080866DC
	adds r6, r5, #0
	adds r6, #0x48
	adds r0, r6, #0
	bl Map_FindNavRectAt
	cmp r0, #0xff
	beq _080866BC
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r4, r5, r2
	adds r0, r4, #0
	adds r1, r6, #0
	bl Map_InitNavAgent
	movs r0, #0xea
	lsls r0, r0, #2
	adds r2, r5, r0
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08235a84
	cmp r0, #0
	bne _080866D4
_080866BC:
	adds r0, r5, #0
	movs r1, #0
	bl Coffin_SetState
	b _080866DC
	.align 2, 0
_080866C8: .4byte 0x03002C00
_080866CC: .4byte 0x000003AA
_080866D0: .4byte 0x000001F5
_080866D4:
	adds r0, r5, #0
	movs r1, #3
	bl Coffin_SetState
_080866DC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
