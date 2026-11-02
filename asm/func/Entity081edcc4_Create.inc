	push {r4, lr}
	ldr r0, _081EDCFC @ =0x030001C8
	ldr r0, [r0]
	cmp r0, #0
	bne _081EDD0A
	movs r1, #0xea
	lsls r1, r1, #1
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081EDD08
	ldr r1, _081EDD00 @ =Entity081edcc4_Update
	ldr r2, _081EDD04 @ =Entity081edcc4_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081edcc4_Init
	cmp r0, #0
	bge _081EDD08
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EDD0A
	.align 2, 0
_081EDCFC: .4byte 0x030001C8
_081EDD00: .4byte Entity081edcc4_Update
_081EDD04: .4byte Entity081edcc4_Destroy
_081EDD08:
	adds r0, r4, #0
_081EDD0A:
	pop {r4}
	pop {r1}
	bx r1
