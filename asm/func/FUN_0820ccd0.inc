	push {lr}
	adds r2, r1, #0
	cmp r0, #0x1f
	bls _0820CCDA
	b _0820CF3C
_0820CCDA:
	lsls r0, r0, #2
	ldr r1, _0820CCE4 @ =_0820CCE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820CCE4: .4byte _0820CCE8
_0820CCE8: @ jump table
	.4byte _0820CF3C @ case 0
	.4byte _0820CD68 @ case 1
	.4byte _0820CD88 @ case 2
	.4byte _0820CDA4 @ case 3
	.4byte _0820CDC4 @ case 4
	.4byte _0820CDE4 @ case 5
	.4byte _0820CDF6 @ case 6
	.4byte _0820CDFA @ case 7
	.4byte _0820CDFE @ case 8
	.4byte _0820CE10 @ case 9
	.4byte _0820CE14 @ case 10
	.4byte _0820CE26 @ case 11
	.4byte _0820CE2A @ case 12
	.4byte _0820CE3C @ case 13
	.4byte _0820CE4E @ case 14
	.4byte _0820CF3C @ case 15
	.4byte _0820CF3C @ case 16
	.4byte _0820CE52 @ case 17
	.4byte _0820CE72 @ case 18
	.4byte _0820CE8E @ case 19
	.4byte _0820CEAA @ case 20
	.4byte _0820CECA @ case 21
	.4byte _0820CEF2 @ case 22
	.4byte _0820CF1A @ case 23
	.4byte _0820CF2C @ case 24
	.4byte _0820CF30 @ case 25
	.4byte _0820CF34 @ case 26
	.4byte _0820CF38 @ case 27
	.4byte _0820CF3C @ case 28
	.4byte _0820CF3C @ case 29
	.4byte _0820CF3C @ case 30
	.4byte _0820CF3C @ case 31
_0820CD68:
	cmp r2, #1
	beq _0820CD80
	cmp r2, #1
	bgt _0820CD76
	cmp r2, #0
	beq _0820CD7C
	b _0820CF3C
_0820CD76:
	cmp r2, #2
	beq _0820CD84
	b _0820CF3C
_0820CD7C:
	movs r0, #0x18
	b _0820CF40
_0820CD80:
	movs r0, #0x19
	b _0820CF40
_0820CD84:
	movs r0, #0x1a
	b _0820CF40
_0820CD88:
	cmp r2, #1
	beq _0820CD9C
	cmp r2, #1
	bgt _0820CD96
	cmp r2, #0
	beq _0820CDA0
	b _0820CF3C
_0820CD96:
	cmp r2, #2
	beq _0820CDA0
	b _0820CF3C
_0820CD9C:
	movs r0, #1
	b _0820CF40
_0820CDA0:
	movs r0, #0
	b _0820CF40
_0820CDA4:
	cmp r2, #1
	beq _0820CDBC
	cmp r2, #1
	bgt _0820CDB2
	cmp r2, #0
	beq _0820CDB8
	b _0820CF3C
_0820CDB2:
	cmp r2, #3
	beq _0820CDC0
	b _0820CF3C
_0820CDB8:
	movs r0, #0x21
	b _0820CF40
_0820CDBC:
	movs r0, #0x22
	b _0820CF40
_0820CDC0:
	movs r0, #0x23
	b _0820CF40
_0820CDC4:
	cmp r2, #2
	beq _0820CDDC
	cmp r2, #2
	bgt _0820CDD2
	cmp r2, #1
	beq _0820CDD8
	b _0820CF3C
_0820CDD2:
	cmp r2, #3
	beq _0820CDE0
	b _0820CF3C
_0820CDD8:
	movs r0, #0x15
	b _0820CF40
_0820CDDC:
	movs r0, #0x16
	b _0820CF40
_0820CDE0:
	movs r0, #0x17
	b _0820CF40
_0820CDE4:
	cmp r2, #0
	beq _0820CDEE
	cmp r2, #5
	beq _0820CDF2
	b _0820CF3C
_0820CDEE:
	movs r0, #0x1b
	b _0820CF40
_0820CDF2:
	movs r0, #0x1e
	b _0820CF40
_0820CDF6:
	movs r0, #0x1c
	b _0820CF40
_0820CDFA:
	movs r0, #0x1d
	b _0820CF40
_0820CDFE:
	cmp r2, #2
	beq _0820CE08
	cmp r2, #8
	beq _0820CE0C
	b _0820CF3C
_0820CE08:
	movs r0, #0x1f
	b _0820CF40
_0820CE0C:
	movs r0, #0x20
	b _0820CF40
_0820CE10:
	movs r0, #9
	b _0820CF40
_0820CE14:
	cmp r2, #0
	beq _0820CE1E
	cmp r2, #1
	beq _0820CE22
	b _0820CF3C
_0820CE1E:
	movs r0, #0x11
	b _0820CF40
_0820CE22:
	movs r0, #0x12
	b _0820CF40
_0820CE26:
	movs r0, #0x24
	b _0820CF40
_0820CE2A:
	cmp r2, #0
	beq _0820CE34
	cmp r2, #1
	beq _0820CE38
	b _0820CF3C
_0820CE34:
	movs r0, #0x25
	b _0820CF40
_0820CE38:
	movs r0, #0x26
	b _0820CF40
_0820CE3C:
	cmp r2, #0
	beq _0820CE46
	cmp r2, #1
	beq _0820CE4A
	b _0820CF3C
_0820CE46:
	movs r0, #0x27
	b _0820CF40
_0820CE4A:
	movs r0, #0x28
	b _0820CF40
_0820CE4E:
	movs r0, #0x10
	b _0820CF40
_0820CE52:
	cmp r2, #1
	beq _0820CE6A
	cmp r2, #1
	bgt _0820CE60
	cmp r2, #0
	beq _0820CE66
	b _0820CF3C
_0820CE60:
	cmp r2, #2
	beq _0820CE6E
	b _0820CF3C
_0820CE66:
	movs r0, #0x29
	b _0820CF40
_0820CE6A:
	movs r0, #0x2a
	b _0820CF40
_0820CE6E:
	movs r0, #0x2b
	b _0820CF40
_0820CE72:
	cmp r2, #1
	beq _0820CE86
	cmp r2, #1
	bgt _0820CE80
	cmp r2, #0
	beq _0820CE8A
	b _0820CF3C
_0820CE80:
	cmp r2, #2
	beq _0820CE8A
	b _0820CF3C
_0820CE86:
	movs r0, #6
	b _0820CF40
_0820CE8A:
	movs r0, #5
	b _0820CF40
_0820CE8E:
	cmp r2, #1
	beq _0820CEA2
	cmp r2, #1
	bgt _0820CE9C
	cmp r2, #0
	beq _0820CEA6
	b _0820CF3C
_0820CE9C:
	cmp r2, #2
	beq _0820CEA6
	b _0820CF3C
_0820CEA2:
	movs r0, #8
	b _0820CF40
_0820CEA6:
	movs r0, #7
	b _0820CF40
_0820CEAA:
	cmp r2, #1
	beq _0820CEC2
	cmp r2, #1
	bgt _0820CEB8
	cmp r2, #0
	beq _0820CEBE
	b _0820CF3C
_0820CEB8:
	cmp r2, #2
	beq _0820CEC6
	b _0820CF3C
_0820CEBE:
	movs r0, #2
	b _0820CF40
_0820CEC2:
	movs r0, #4
	b _0820CF40
_0820CEC6:
	movs r0, #3
	b _0820CF40
_0820CECA:
	cmp r2, #1
	beq _0820CEE6
	cmp r2, #1
	bgt _0820CED8
	cmp r2, #0
	beq _0820CEE2
	b _0820CF3C
_0820CED8:
	cmp r2, #2
	beq _0820CEEA
	cmp r2, #4
	beq _0820CEEE
	b _0820CF3C
_0820CEE2:
	movs r0, #0xa
	b _0820CF40
_0820CEE6:
	movs r0, #0xc
	b _0820CF40
_0820CEEA:
	movs r0, #0xb
	b _0820CF40
_0820CEEE:
	movs r0, #0xd
	b _0820CF40
_0820CEF2:
	cmp r2, #1
	beq _0820CF0E
	cmp r2, #1
	bgt _0820CF00
	cmp r2, #0
	beq _0820CF0A
	b _0820CF3C
_0820CF00:
	cmp r2, #2
	beq _0820CF12
	cmp r2, #3
	beq _0820CF16
	b _0820CF3C
_0820CF0A:
	movs r0, #0x2c
	b _0820CF40
_0820CF0E:
	movs r0, #0x2d
	b _0820CF40
_0820CF12:
	movs r0, #0x2e
	b _0820CF40
_0820CF16:
	movs r0, #0x2f
	b _0820CF40
_0820CF1A:
	cmp r2, #0
	beq _0820CF24
	cmp r2, #1
	beq _0820CF28
	b _0820CF3C
_0820CF24:
	movs r0, #0x30
	b _0820CF40
_0820CF28:
	movs r0, #0x31
	b _0820CF40
_0820CF2C:
	movs r0, #0xe
	b _0820CF40
_0820CF30:
	movs r0, #0x13
	b _0820CF40
_0820CF34:
	movs r0, #0x14
	b _0820CF40
_0820CF38:
	movs r0, #0xf
	b _0820CF40
_0820CF3C:
	movs r0, #1
	rsbs r0, r0, #0
_0820CF40:
	pop {r1}
	bx r1
