	push {r4, lr}
	ldr r0, _081EEEB4 @ =0x030001D8
	ldr r0, [r0]
	cmp r0, #0
	bne _081EEEC6
	ldr r1, _081EEEB8 @ =0x00002038
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081EEEC4
	ldr r1, _081EEEBC @ =Entity081eee80_Update
	ldr r2, _081EEEC0 @ =Entity081eee80_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081eee80_Init
	cmp r0, #0
	bge _081EEEC4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EEEC6
	.align 2, 0
_081EEEB4: .4byte 0x030001D8
_081EEEB8: .4byte 0x00002038
_081EEEBC: .4byte Entity081eee80_Update
_081EEEC0: .4byte Entity081eee80_Destroy
_081EEEC4:
	adds r0, r4, #0
_081EEEC6:
	pop {r4}
	pop {r1}
	bx r1
