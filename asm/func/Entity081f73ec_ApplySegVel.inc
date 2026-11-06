	push {r4, r5, lr}
	adds r2, r0, #0
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r3, #0x92
	lsls r3, r3, #1
	ldr r5, _081F5CF8 @ =0x000005B4
	adds r4, r2, r5
_081F5CD2:
	ldrh r0, [r1]
	ldrh r5, [r2, #0x1c]
	adds r0, r0, r5
	strh r0, [r2, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r5, [r2, #0x1e]
	adds r0, r0, r5
	strh r0, [r2, #0x1e]
	ldrh r0, [r1, #4]
	ldrh r5, [r2, #0x20]
	adds r0, r0, r5
	strh r0, [r2, #0x20]
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r0, #0
	blt _081F5CFC
	asrs r0, r0, #1
	b _081F5D02
	.align 2, 0
_081F5CF8: .4byte 0x000005B4
_081F5CFC:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081F5D02:
	strh r0, [r1]
	movs r5, #2
	ldrsh r0, [r1, r5]
	cmp r0, #0
	blt _081F5D10
	asrs r0, r0, #1
	b _081F5D16
_081F5D10:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081F5D16:
	strh r0, [r1, #2]
	movs r5, #4
	ldrsh r0, [r1, r5]
	cmp r0, #0
	blt _081F5D24
	asrs r0, r0, #1
	b _081F5D2A
_081F5D24:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081F5D2A:
	strh r0, [r1, #4]
	adds r2, r2, r3
	adds r1, r1, r3
	cmp r2, r4
	ble _081F5CD2
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
