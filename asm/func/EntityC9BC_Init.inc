	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0800DA4C @ =0x03002B38
	str r5, [r0]
	movs r4, #0
	str r4, [r5, #0x18]
	ldr r1, [r5, #0x1c]
	lsls r0, r1, #7
	subs r0, r0, r1
	lsls r0, r0, #2
	bl Malloc
	adds r2, r0, #0
	str r2, [r5, #0x74]
	cmp r2, #0
	bne _0800DA50
	movs r0, #1
	rsbs r0, r0, #0
	b _0800DAB8
	.align 2, 0
_0800DA4C: .4byte 0x03002B38
_0800DA50:
	ldr r0, [r5, #0x1c]
	lsls r1, r0, #7
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r0, r2, #0
	bl ClearMemory
	adds r0, r5, #0
	adds r0, #0x23
	strb r4, [r0]
	strh r4, [r5, #0x24]
	ldr r0, _0800DAC0 @ =0x03003584
	ldr r1, [r0]
	movs r2, #0xf0
	lsls r2, r2, #4
	adds r0, r1, r2
	str r0, [r5, #0x28]
	movs r3, #0xf2
	lsls r3, r3, #4
	adds r2, r1, r3
	str r2, [r5, #0x2c]
	movs r2, #0xf4
	lsls r2, r2, #4
	adds r1, r1, r2
	str r1, [r5, #0x30]
	adds r1, r5, #0
	adds r1, #0x34
	ldr r4, _0800DAC4 @ =0x04000008
	adds r2, r4, #0
	bl CpuSet
	ldr r0, [r5, #0x28]
	adds r1, r5, #0
	adds r1, #0x54
	adds r2, r4, #0
	bl CpuSet
	ldr r1, [r5, #0x74]
	movs r2, #0
	ldr r0, [r5, #0x1c]
	cmp r2, r0
	bhs _0800DAB6
	movs r4, #0
	movs r3, #0xfe
	lsls r3, r3, #1
_0800DAAA:
	strb r4, [r1]
	adds r2, #1
	adds r1, r1, r3
	ldr r0, [r5, #0x1c]
	cmp r2, r0
	blo _0800DAAA
_0800DAB6:
	movs r0, #0
_0800DAB8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800DAC0: .4byte 0x03003584
_0800DAC4: .4byte 0x04000008
