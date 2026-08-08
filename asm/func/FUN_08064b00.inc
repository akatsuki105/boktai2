	push {lr}
	adds r2, r0, #0
	ldr r0, _08064B18 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	bne _08064B20
	ldr r0, _08064B1C @ =0x085ABACC
	b _08064B22
	.align 2, 0
_08064B18: .4byte 0x030047A4
_08064B1C: .4byte 0x085ABACC
_08064B20:
	ldr r0, _08064B2C @ =0x085ABAF0
_08064B22:
	lsls r1, r2, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08064B2C: .4byte 0x085ABAF0
