	push {r4, lr}
	ldr r0, _0809C738 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r4, r0, r1
	cmp r0, #0
	bne _0809C71E
	movs r4, #0
_0809C71E:
	movs r0, #0
	movs r1, #0x19
	movs r2, #2
	bl FUN_0808a420
	adds r1, r0, #0
	movs r2, #4
_0809C72C:
	ldrb r0, [r4]
	cmp r0, #0
	bne _0809C740
	ldr r3, _0809C73C @ =0x0000E0C0
	b _0809C766
	.align 2, 0
_0809C738: .4byte 0x03002C68
_0809C73C: .4byte 0x0000E0C0
_0809C740:
	cmp r0, #1
	bne _0809C74C
	ldr r3, _0809C748 @ =0x0000E0C3
	b _0809C766
	.align 2, 0
_0809C748: .4byte 0x0000E0C3
_0809C74C:
	cmp r0, #2
	bne _0809C758
	ldr r3, _0809C754 @ =0x0000E0C2
	b _0809C766
	.align 2, 0
_0809C754: .4byte 0x0000E0C2
_0809C758:
	cmp r0, #3
	bne _0809C764
	ldr r3, _0809C760 @ =0x0000E0C1
	b _0809C766
	.align 2, 0
_0809C760: .4byte 0x0000E0C1
_0809C764:
	ldr r3, _0809C77C @ =0x0000E0C4
_0809C766:
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	adds r4, #1
	subs r2, #1
	cmp r2, #0
	bge _0809C72C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C77C: .4byte 0x0000E0C4
