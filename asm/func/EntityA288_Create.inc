	push {r4, lr}
	ldr r1, _0821A2A8 @ =0x00001FEC
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0821A2B4
	ldr r1, _0821A2AC @ =EntityA288_Update
	ldr r2, _0821A2B0 @ =EntityA288_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityA288_Init
	cmp r0, #0
	bge _0821A2B4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0821A2B6
	.align 2, 0
_0821A2A8: .4byte 0x00001FEC
_0821A2AC: .4byte EntityA288_Update
_0821A2B0: .4byte EntityA288_Destroy
_0821A2B4:
	adds r0, r4, #0
_0821A2B6:
	pop {r4}
	pop {r1}
	bx r1
