	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, _08004E24 @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	bne _08004E28
	movs r0, #1
	rsbs r0, r0, #0
	b _08004E44
	.align 2, 0
_08004E24: .4byte 0x03000024
_08004E28:
	ldr r1, [r0, #0x18]
	cmp r1, #0
	beq _08004E42
_08004E2E:
	ldr r4, [r1, #0x20]
	ldrh r0, [r1]
	cmp r0, r5
	bne _08004E3C
	adds r0, r1, #0
	bl Entity08004fac_FreeNode
_08004E3C:
	adds r1, r4, #0
	cmp r1, #0
	bne _08004E2E
_08004E42:
	movs r0, #0
_08004E44:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
