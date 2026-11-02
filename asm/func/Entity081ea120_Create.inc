	push {r4, r5, lr}
	ldr r5, _081EA15C @ =0x030001B8
	ldr r0, [r5]
	cmp r0, #0
	bne _081EA16A
	movs r1, #0x9f
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	str r4, [r5]
	cmp r4, #0
	beq _081EA168
	ldr r1, _081EA160 @ =Entity081ea120_Update
	ldr r2, _081EA164 @ =Entity081ea120_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	movs r1, #0
	bl Entity081ea120_Init
	cmp r0, #0
	bge _081EA168
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EA16A
	.align 2, 0
_081EA15C: .4byte 0x030001B8
_081EA160: .4byte Entity081ea120_Update
_081EA164: .4byte Entity081ea120_Destroy
_081EA168:
	adds r0, r4, #0
_081EA16A:
	pop {r4, r5}
	pop {r1}
	bx r1
