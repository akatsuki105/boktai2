	push {r4, lr}
	ldr r0, _081D9A3C @ =0x030001A4
	ldr r0, [r0]
	cmp r0, #0
	bne _081D9A4E
	ldr r1, _081D9A40 @ =0x00000ED4
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D9A4C
	ldr r1, _081D9A44 @ =Entity8CC7_Update
	ldr r2, _081D9A48 @ =Entity8CC7_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity8CC7_Init
	cmp r0, #0
	bge _081D9A4C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D9A4E
	.align 2, 0
_081D9A3C: .4byte 0x030001A4
_081D9A40: .4byte 0x00000ED4
_081D9A44: .4byte Entity8CC7_Update
_081D9A48: .4byte Entity8CC7_Destroy
_081D9A4C:
	adds r0, r4, #0
_081D9A4E:
	pop {r4}
	pop {r1}
	bx r1
