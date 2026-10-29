	push {r4, lr}
	ldr r0, _081EFAD0 @ =0x030001DC
	ldr r0, [r0]
	cmp r0, #0
	bne _081EFAE2
	ldr r1, _081EFAD4 @ =0x0000083C
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081EFAE0
	ldr r1, _081EFAD8 @ =Entity081efa9c_Update
	ldr r2, _081EFADC @ =Entity081efa9c_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081efa9c_Init
	cmp r0, #0
	bge _081EFAE0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EFAE2
	.align 2, 0
_081EFAD0: .4byte 0x030001DC
_081EFAD4: .4byte 0x0000083C
_081EFAD8: .4byte Entity081efa9c_Update
_081EFADC: .4byte Entity081efa9c_Destroy
_081EFAE0:
	adds r0, r4, #0
_081EFAE2:
	pop {r4}
	pop {r1}
	bx r1
