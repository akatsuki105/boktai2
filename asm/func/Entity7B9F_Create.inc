	push {r4, lr}
	ldr r0, _081D8890 @ =0x030001A0
	ldr r0, [r0]
	cmp r0, #0
	bne _081D889E
	movs r1, #0xeb
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D889C
	ldr r1, _081D8894 @ =Entity7B9F_Update
	ldr r2, _081D8898 @ =Entity7B9F_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity7B9F_Init
	cmp r0, #0
	bge _081D889C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D889E
	.align 2, 0
_081D8890: .4byte 0x030001A0
_081D8894: .4byte Entity7B9F_Update
_081D8898: .4byte Entity7B9F_Destroy
_081D889C:
	adds r0, r4, #0
_081D889E:
	pop {r4}
	pop {r1}
	bx r1
