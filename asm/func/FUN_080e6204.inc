	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	mov r5, sp
	adds r0, #0x9c
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r5, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _080E623C
	cmp r1, #0
	blt _080E623C
	ldr r0, _080E6240 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080E623C
	ldr r0, _080E6244 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080E6248
_080E623C:
	movs r4, #0
	b _080E6256
	.align 2, 0
_080E6240: .4byte 0x030046A8
_080E6244: .4byte 0x030046AC
_080E6248:
	ldr r0, _080E6268 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080E6256:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E626C
	adds r0, #4
	b _080E6278
	.align 2, 0
_080E6268: .4byte 0x030046A4
_080E626C:
	ldr r0, _080E628C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E6278:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080E6290
	cmp r2, #2
	beq _080E6294
	b _080E6298
	.align 2, 0
_080E628C: .4byte 0x030046A4
_080E6290:
	ldrb r0, [r5, #4]
	b _080E6296
_080E6294:
	ldrb r0, [r5]
_080E6296:
	subs r1, r1, r0
_080E6298:
	strh r1, [r5, #2]
	ldrh r1, [r6, #0xa]
	mov r0, sp
	strh r1, [r0, #2]
	ldr r1, _080E62D8 @ =0x000004A4
	adds r0, r6, r1
	ldr r4, [r0]
	adds r5, r6, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	beq _080E62DC
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _080E62DC
	cmp r0, #2
	beq _080E62D4
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_080E62D4:
	movs r0, #1
	b _080E62EC
	.align 2, 0
_080E62D8: .4byte 0x000004A4
_080E62DC:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, _080E6300 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_080E62EC:
	cmp r0, #0
	bne _080E62F6
	mov r0, sp
	bl FUN_081fa26c
_080E62F6:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080E6300: .4byte 0xFFFFFDFF
