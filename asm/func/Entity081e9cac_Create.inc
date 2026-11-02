	push {r4, lr}
	ldr r0, _081E9CE0 @ =0x030001B4
	ldr r0, [r0]
	cmp r0, #0
	bne _081E9CF2
	ldr r1, _081E9CE4 @ =0x00000BAC
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081E9CF0
	ldr r1, _081E9CE8 @ =Entity081e9cac_Update
	ldr r2, _081E9CEC @ =Entity081e9cac_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081e9cac_Init
	cmp r0, #0
	bge _081E9CF0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081E9CF2
	.align 2, 0
_081E9CE0: .4byte 0x030001B4
_081E9CE4: .4byte 0x00000BAC
_081E9CE8: .4byte Entity081e9cac_Update
_081E9CEC: .4byte Entity081e9cac_Destroy
_081E9CF0:
	adds r0, r4, #0
_081E9CF2:
	pop {r4}
	pop {r1}
	bx r1
