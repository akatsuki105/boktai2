	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _081972BC @ =0x00000AC6
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08197304
	subs r0, #1
	strh r0, [r1]
	b _08197334
	.align 2, 0
_081972BC: .4byte 0x00000AC6
_081972C0:
	adds r0, r5, r4
	ldr r1, _081972F4 @ =0x0000053C
	adds r0, r0, r1
	movs r1, #1
	adds r2, r0, #0
	adds r2, #0x2e
	strb r1, [r2]
	adds r2, #1
	strb r3, [r2]
	adds r0, #0x29
	ldrb r2, [r0]
	orrs r1, r2
	strb r1, [r0]
	movs r2, #0xb6
	lsls r2, r2, #3
	adds r0, r4, r2
	adds r0, r0, r5
	ldr r1, _081972F8 @ =FUN_08199aa4
	str r1, [r0]
	ldr r1, _081972FC @ =0x00000AC4
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _08197300 @ =0x00000AC6
	adds r0, r4, r2
	strh r1, [r0]
	b _08197334
	.align 2, 0
_081972F4: .4byte 0x0000053C
_081972F8: .4byte FUN_08199aa4
_081972FC: .4byte 0x00000AC4
_08197300: .4byte 0x00000AC6
_08197304:
	movs r1, #0
	ldr r2, _0819733C @ =0x00000C9C
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r1, r0
	bge _0819732C
	adds r6, r0, #0
	ldr r2, _08197340 @ =0x0000056A
	adds r0, r4, r2
	movs r5, #0
	movs r2, #0xc6
	lsls r2, r2, #1
_0819731C:
	ldrb r3, [r0]
	cmp r3, #0
	beq _081972C0
	adds r0, r0, r2
	adds r5, r5, r2
	adds r1, #1
	cmp r1, r6
	blt _0819731C
_0819732C:
	ldr r0, _08197344 @ =0x00000C54
	adds r1, r4, r0
	ldr r0, _08197348 @ =FUN_0819734c
	str r0, [r1]
_08197334:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819733C: .4byte 0x00000C9C
_08197340: .4byte 0x0000056A
_08197344: .4byte 0x00000C54
_08197348: .4byte FUN_0819734c
