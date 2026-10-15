	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	ldr r4, _081E284C @ =0x0000CB05
	ldr r1, _081E2850 @ =0x0000DCC1
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	ldr r2, _081E2854 @ =0x00000AE8
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x40
	adds r0, r5, r2
	bl OpenMainSpriteFile
	ldr r1, _081E2858 @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	ldr r2, _081E285C @ =0x00000AEC
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x24
	adds r0, r5, r2
	bl OpenMainSpriteFile
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _081E2860 @ =0x05000002
	bl CpuSet
	movs r6, #0
_081E283A:
	cmp r6, #0xf
	bgt _081E2868
	movs r1, #0xaf
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrh r2, [r0]
	ldr r0, _081E2864 @ =0x00000AA8
	b _081E2910
	.align 2, 0
_081E284C: .4byte 0x0000CB05
_081E2850: .4byte 0x0000DCC1
_081E2854: .4byte 0x00000AE8
_081E2858: .4byte 0x0000B343
_081E285C: .4byte 0x00000AEC
_081E2860: .4byte 0x05000002
_081E2864: .4byte 0x00000AA8
_081E2868:
	cmp r6, #0x14
	bgt _081E28D4
	adds r0, r6, #0
	subs r0, #0x10
	cmp r0, #4
	bhi _081E28C8
	lsls r0, r0, #2
	ldr r1, _081E2880 @ =_081E2884
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081E2880: .4byte _081E2884
_081E2884: @ jump table
	.4byte _081E2898 @ case 0
	.4byte _081E28A0 @ case 1
	.4byte _081E28A8 @ case 2
	.4byte _081E28B0 @ case 3
	.4byte _081E28BC @ case 4
_081E2898:
	ldr r1, _081E289C @ =0x00000B18
	b _081E28BE
	.align 2, 0
_081E289C: .4byte 0x00000B18
_081E28A0:
	ldr r2, _081E28A4 @ =0x00000B1A
	b _081E28B2
	.align 2, 0
_081E28A4: .4byte 0x00000B1A
_081E28A8:
	ldr r1, _081E28AC @ =0x00000B1C
	b _081E28BE
	.align 2, 0
_081E28AC: .4byte 0x00000B1C
_081E28B0:
	ldr r2, _081E28B8 @ =0x00000B1E
_081E28B2:
	adds r0, r5, r2
	ldrh r2, [r0]
	b _081E28CA
	.align 2, 0
_081E28B8: .4byte 0x00000B1E
_081E28BC:
	ldr r1, _081E28C4 @ =0x00000B2E
_081E28BE:
	adds r0, r5, r1
	ldrh r2, [r0]
	b _081E28CA
	.align 2, 0
_081E28C4: .4byte 0x00000B2E
_081E28C8:
	movs r2, #0
_081E28CA:
	ldr r0, _081E28D0 @ =0x00000AA8
	b _081E2910
	.align 2, 0
_081E28D0: .4byte 0x00000AA8
_081E28D4:
	cmp r6, #0x15
	bgt _081E28EC
	lsls r1, r6, #1
	movs r2, #0xaf
	lsls r2, r2, #4
	adds r0, r5, r2
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r0, _081E28E8 @ =0x00000AC8
	b _081E292E
	.align 2, 0
_081E28E8: .4byte 0x00000AC8
_081E28EC:
	cmp r6, #0x19
	bgt _081E28F8
	ldr r1, _081E28F4 @ =0x00000B22
	b _081E290A
	.align 2, 0
_081E28F4: .4byte 0x00000B22
_081E28F8:
	cmp r6, #0x1a
	bgt _081E2904
	ldr r1, _081E2900 @ =0x00000B2A
	b _081E290A
	.align 2, 0
_081E2900: .4byte 0x00000B2A
_081E2904:
	cmp r6, #0x1b
	bgt _081E2920
	ldr r1, _081E2918 @ =0x00000B26
_081E290A:
	adds r0, r5, r1
	ldrh r2, [r0]
	ldr r0, _081E291C @ =0x00000AC8
_081E2910:
	adds r3, r5, r0
	lsls r1, r6, #1
	b _081E2930
	.align 2, 0
_081E2918: .4byte 0x00000B26
_081E291C: .4byte 0x00000AC8
_081E2920:
	lsls r1, r6, #1
	movs r2, #0xaf
	lsls r2, r2, #4
	adds r0, r5, r2
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r0, _081E295C @ =0x00000AA8
_081E292E:
	adds r3, r5, r0
_081E2930:
	adds r0, r1, r6
	lsls r0, r0, #5
	adds r0, #0x28
	adds r0, r5, r0
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	adds r1, r3, #0
	movs r3, #0x10
	bl MainSprite_Add
	adds r6, #1
	cmp r6, #0x1b
	bgt _081E2952
	b _081E283A
_081E2952:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E295C: .4byte 0x00000AA8
