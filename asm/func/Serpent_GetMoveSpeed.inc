	push {r4, lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	ldr r1, _08191218 @ =0x00000546
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r0, r2, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	ble _0819123C
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #0x10
	ldr r2, _0819121C @ =0x00000F2C
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08191220
	movs r0, #1
	b _08191222
	.align 2, 0
_08191218: .4byte 0x00000546
_0819121C: .4byte 0x00000F2C
_08191220:
	movs r0, #0
_08191222:
	cmp r0, #0
	beq _08191278
	ldr r2, _08191238 @ =0x085ADD54
	ldrh r1, [r3, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r0, r0, #2
	b _08191288
	.align 2, 0
_08191238: .4byte 0x085ADD54
_0819123C:
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r2, r4
	ldr r0, [r0]
	movs r1, #0x10
	ldr r2, _08191258 @ =0x00000F2C
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819125C
	movs r0, #1
	b _0819125E
	.align 2, 0
_08191258: .4byte 0x00000F2C
_0819125C:
	movs r0, #0
_0819125E:
	cmp r0, #0
	bne _08191278
	ldr r2, _08191274 @ =0x085ADD54
	ldrh r1, [r3, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	b _08191288
	.align 2, 0
_08191274: .4byte 0x085ADD54
_08191278:
	ldr r2, _08191290 @ =0x085ADD54
	ldrh r1, [r3, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r0, r0, #1
_08191288:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08191290: .4byte 0x085ADD54
