	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r0, _08234F60 @ =0x030046A4
	ldr r0, [r0]
	ldr r1, [r0, #0x10]
	ldrh r0, [r1]
	cmp r2, r0
	bhs _08234F64
	lsls r0, r2, #2
	adds r0, #4
	adds r0, r1, r0
	b _08234F66
	.align 2, 0
_08234F60: .4byte 0x030046A4
_08234F64:
	movs r0, #0
_08234F66:
	pop {r1}
	bx r1
	.align 2, 0
