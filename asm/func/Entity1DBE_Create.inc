	push {r4, lr}
	ldr r1, _0809FF70 @ =0x000007BC
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0809FF7C
	ldr r1, _0809FF74 @ =Entity1DBE_Update
	ldr r2, _0809FF78 @ =Entity1DBE_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity1DBE_Init
	cmp r0, #0
	bge _0809FF7C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0809FF7E
	.align 2, 0
_0809FF70: .4byte 0x000007BC
_0809FF74: .4byte Entity1DBE_Update
_0809FF78: .4byte Entity1DBE_Destroy
_0809FF7C:
	adds r0, r4, #0
_0809FF7E:
	pop {r4}
	pop {r1}
	bx r1
