	push {r4, r5, r6, lr}
	ldr r0, _0824768C @ =ROM_GPIODATA
	ldrh r3, [r0]
	ldr r2, _08247690 @ =0x030026C0
	ldr r4, [r2]
	strh r4, [r0]
	ldr r1, _08247694 @ =0x0400010C
	ldr r0, _08247698 @ =0x030057CC
	ldr r0, [r0]
	rsbs r0, r0, #0
	strh r0, [r1]
	movs r5, #8
	ands r5, r3
	ldr r0, _0824769C @ =0x030057BC
	str r5, [r0]
	ldr r0, _082476A0 @ =0x030057B8
	ldr r0, [r0]
	cmp r0, #0
	beq _08247722
	ldr r0, _082476A4 @ =0x030026B4
	ldr r1, [r0]
	adds r3, r0, #0
	cmp r1, #1
	beq _082476F0
	cmp r1, #1
	bgt _082476AC
	cmp r1, #0
	beq _082476B8
	ldr r6, _082476A8 @ =0x030026B8
	b _0824771C
	.align 2, 0
_0824768C: .4byte ROM_GPIODATA
_08247690: .4byte 0x030026C0
_08247694: .4byte 0x0400010C
_08247698: .4byte 0x030057CC
_0824769C: .4byte 0x030057BC
_082476A0: .4byte 0x030057B8
_082476A4: .4byte 0x030026B4
_082476A8: .4byte 0x030026B8
_082476AC:
	ldr r6, _082476B4 @ =0x030026B8
	cmp r1, #2
	beq _08247706
	b _0824771C
	.align 2, 0
_082476B4: .4byte 0x030026B8
_082476B8:
	ldr r0, _082476C8 @ =0x030026B8
	ldr r1, [r0]
	adds r6, r0, #0
	cmp r1, #9
	bgt _082476CC
	movs r0, #2
	orrs r4, r0
	b _082476D2
	.align 2, 0
_082476C8: .4byte 0x030026B8
_082476CC:
	movs r0, #3
	rsbs r0, r0, #0
	ands r4, r0
_082476D2:
	str r4, [r2]
	ldr r0, [r6]
	cmp r0, #0x14
	ble _0824771C
	cmp r5, #0
	bne _0824771C
	ldr r0, [r3]
	adds r0, #1
	str r0, [r3]
	str r5, [r6]
	ldr r0, _082476EC @ =0x030026BC
	str r5, [r0]
	b _0824771C
	.align 2, 0
_082476EC: .4byte 0x030026BC
_082476F0:
	ldr r6, _08247728 @ =0x030026B8
	cmp r5, #0
	beq _08247702
	ldr r0, _0824772C @ =0x030057C8
	ldr r1, [r6]
	asrs r1, r1, #1
	str r1, [r0]
	movs r0, #2
	str r0, [r3]
_08247702:
	ldr r0, _08247730 @ =0x030026BC
	str r5, [r0]
_08247706:
	ldr r0, [r2]
	movs r1, #1
	eors r0, r1
	str r0, [r2]
	ldr r1, [r6]
	ldr r0, _08247734 @ =0x000001FF
	cmp r1, r0
	ble _0824771C
	movs r0, #0
	str r0, [r3]
	str r0, [r6]
_0824771C:
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
_08247722:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08247728: .4byte 0x030026B8
_0824772C: .4byte 0x030057C8
_08247730: .4byte 0x030026BC
_08247734: .4byte 0x000001FF
